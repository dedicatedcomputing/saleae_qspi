#include <map>
#include "QSPIAnalyzerCommands.h"

void QSPIMakeCommandList();

std::map<U64, CommandAttr> qspi_cmds;

void QSPIMakeCommandList() {
	qspi_cmds[0x66] = CommandAttr{ false,false,false,false,0x00,0x00,"Reset Enable" };
	qspi_cmds[0x99] = CommandAttr{ false,false,false,false,0x00,0x00,"Reset Memory" };
	qspi_cmds[0x9E] = CommandAttr{ false,false,true,false,0x00,0x02,"Read Id" };
	qspi_cmds[0x9F] = CommandAttr{ false,false,true,false,0x00,0x02,"Read Id" };
	qspi_cmds[0xAF] = CommandAttr{ false,false,true,false,0x00,0x02,"Multiple I/O Read Id" };
	qspi_cmds[0x5A] = CommandAttr{ true,true,true,false,0x01,0x02,"Read Flash Disc Param" };
	qspi_cmds[0x03] = CommandAttr{ true,false,true,false,0x01,0x02,"Read" };
	qspi_cmds[0x0B] = CommandAttr{ true,true,true,false,0x01,0x02,"Fast Read" };
	qspi_cmds[0x3B] = CommandAttr{ true,true,true,false,0x01,0x03,"Dual Output Fast Read" };
	qspi_cmds[0xBB] = CommandAttr{ true,true,true,false,0x03,0x03,"Dual I/O Fast Read" };
	qspi_cmds[0x6B] = CommandAttr{ true,true,true,false,0x01,0x0F,"Quad Output Fast Read" };
	qspi_cmds[0xEB] = CommandAttr{ true,true,true,false,0x0F,0x0F,"Quad I/O Fast Read" };
	qspi_cmds[0x06] = CommandAttr{ false,false,false,false,0x00,0x00,"Write Enable" };
	qspi_cmds[0x04] = CommandAttr{ false,false,false,false,0x00,0x00,"Write Disable" };
	qspi_cmds[0x05] = CommandAttr{ false,false,true,false,0x00,0x02,"Read Status Reg" };
	qspi_cmds[0x01] = CommandAttr{ false,false,true,true,0x00,0x01,"Write Status Reg" };
	qspi_cmds[0xE8] = CommandAttr{ true,false,true,false,0x01,0x02,"Read Lock Reg" };
	qspi_cmds[0xE5] = CommandAttr{ true,false,true,true,0x01,0x01,"Write Lock Reg" };
	qspi_cmds[0x70] = CommandAttr{ false,false,true,false,0x00,0x02,"Read Flag Status Reg" };
	qspi_cmds[0x50] = CommandAttr{ false,false,false,false,0x00,0x00,"Clear Flag Status Reg" };
	qspi_cmds[0xB5] = CommandAttr{ false,false,true,false,0x00,0x02,"Read NonVol Cfg Reg" };
	qspi_cmds[0xB1] = CommandAttr{ false,false,true,true,0x00,0x01,"Write NonVol Cfg Reg" };
	qspi_cmds[0x85] = CommandAttr{ false,false,true,false,0x00,0x02,"Read Vol Cfg Reg" };
	qspi_cmds[0x81] = CommandAttr{ false,false,true,true,0x00,0x01,"Write Vol Cfg Reg" };
	qspi_cmds[0x65] = CommandAttr{ false,false,true,false,0x00,0x02,"Read En Vol Cfg Reg" };
	qspi_cmds[0x61] = CommandAttr{ false,false,true,true,0x00,0x01,"Write En Vol Cfg Reg" };
	qspi_cmds[0x02] = CommandAttr{ true,false,true,true,0x01,0x01,"Page Pgm" };
	qspi_cmds[0xA2] = CommandAttr{ true,false,true,true,0x01,0x03,"Dual Input Fast Pgm" };
	qspi_cmds[0xD2] = CommandAttr{ true,false,true,true,0x03,0x03,"Ext Dual Input Fast Pgm" };
	qspi_cmds[0x32] = CommandAttr{ true,false,true,true,0x01,0x0F,"Quad Input Fast Pgm" };
	qspi_cmds[0x12] = CommandAttr{ true,false,true,true,0x0F,0x0F,"Ext Quad Input Fast Pgm" };
	qspi_cmds[0x20] = CommandAttr{ true,false,false,false,0x01,0x00,"Subsector Erase" };
	qspi_cmds[0xD8] = CommandAttr{ true,false,false,false,0x01,0x00,"Sector Erase" };
	qspi_cmds[0xC7] = CommandAttr{ false,false,false,false,0x00,0x00,"Bulk Erase" };
	qspi_cmds[0x7A] = CommandAttr{ false,false,false,false,0x00,0x00,"Pgm/Erase Resume" };
	qspi_cmds[0x75] = CommandAttr{ false,false,false,false,0x00,0x00,"Pgm/Erase Suspend" };
	qspi_cmds[0x4B] = CommandAttr{ true,true,true,false,0x01,0x02,"Read OTP Array" };
	qspi_cmds[0x42] = CommandAttr{ true,false,true,true,0x01,0x01,"Pgm OTP Array" };
	qspi_cmds[0xB9] = CommandAttr{ false,false,false,false,0x00,0x00,"Deep Power-Down" };
	qspi_cmds[0xAB] = CommandAttr{ false,false,false,false,0x00,0x00,"Release From DPD" };

	qspi_cmds[0xFE] = CommandAttr{ false,false,false,false,0x00,0x00,"ERROR, the world is about to end" };
}

U64 GetQSPICommand(U64 index)
{
	std::vector<U64> commandlist;

	if (qspi_cmds.size() == 0)
	{
		QSPIMakeCommandList();
	}

	// http://stackoverflow.com/questions/110157/how-to-retrieve-all-keys-or-values-from-a-stdmap
	for(std::map<U64, CommandAttr>::iterator it = qspi_cmds.begin(); it != qspi_cmds.end(); ++it)
	{
  	commandlist.push_back(it->first);
  	//cout << it->first << "\n";
	}
	return commandlist.at(index);
}


const CommandAttr& GetQSPICommandAttr(U64 id)
{
	if (qspi_cmds.size() == 0)
	{
		QSPIMakeCommandList();
	}

	if (IsCommandValid(id))
	{
		return qspi_cmds[id];
	}
	else
	{
		return qspi_cmds[0xFE]; // error state
	}
}

bool IsCommandValid(U64 id) {
	if (qspi_cmds.size() == 0)
	{
		QSPIMakeCommandList();
	}

	if (qspi_cmds.find(id) == qspi_cmds.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}
