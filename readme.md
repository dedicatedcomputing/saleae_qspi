# Quad SPI / Dual SPI Flash Memory protocol analyzer for Saleae Logic

The QSPI analyzer is based on Saleae's Sample Analyzer and Analyzer SDK. It is used to decode Flash Memory protocol data from captured waveforms.

The libraries required to build a custom analyzer are stored in another git repository, located here:
[https://github.com/saleae/AnalyzerSDK](https://github.com/saleae/AnalyzerSDK)

Note - This repository contains a submodule. Be sure to include submodules when cloning, for example `git clone --recursive https://github.com/saleae/SampleAnalyzer.git`. If you download the repository from Github, the submodules are not included. In that case you will also need to download the AnalyzerSDK repository linked above and place the AnalyzerSDK folder inside of the SampleAnalyzer folder.

*Note: an additional submodule is used for debugging on Windows, see section on Windows debugging for more information.*

To build on Windows, open the visual studio project in the Visual Studio folder, and build. The Visual Studio solution has configurations for 32 bit and 64 bit builds. You will likely need to switch the configuration to 64 bit and build that in order to get the analyzer to load in the Windows software.

To build on Linux or OSX, run the build_analyzer.py script. The compiled libraries can be found in the newly created debug and release folders.

	python build_analyzer.py

To debug on Windows, please first review the section titled `Debugging an Analyzer with Visual Studio` in the included `doc/Analyzer SDK Setup.md` document.

Unfortunately, debugging is limited on Windows to using an older copy of the Saleae Logic software that does not support the latest hardware devices. Details are included in the above document.
