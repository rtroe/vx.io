##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=vxpad
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Robert\Documents\GitHub\vx.io"
ProjectPath            := "C:\Users\Robert\Documents\GitHub\vx.io\vxpad"
IntermediateDirectory  :=./bin/win/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Robert
Date                   :=13/06/2016
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:/GNU/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/GNU/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="vxpad.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := $(shell wx-config --rcflags)
RcCompilerName         :=C:/GNU/MinGW/bin/windres.exe
LinkOptions            :=  $(shell wx-config --libs --debug) -mwindows
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/GNU/MinGW/bin/ar.exe rcu
CXX      := C:/GNU/MinGW/bin/g++.exe
CC       := C:/GNU/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(shell wx-config --cflags --debug) $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/GNU/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
WXWIN:=C:/wxWidgets
WXCFG:=gcc_dll/mswud
Objects0=$(IntermediateDirectory)/controls_textctrl.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) $(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) $(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) $(IntermediateDirectory)/win_resources.rc$(ObjectSuffix) $(IntermediateDirectory)/gui_vxAUIToolbarArt.cpp$(ObjectSuffix) $(IntermediateDirectory)/gui_vxAuiTabArt.cpp$(ObjectSuffix) $(IntermediateDirectory)/gui_Icon.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./bin/win/Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./bin/win/Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/controls_textctrl.cpp$(ObjectSuffix): controls/textctrl.cpp $(IntermediateDirectory)/controls_textctrl.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxpad/controls/textctrl.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/controls_textctrl.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/controls_textctrl.cpp$(DependSuffix): controls/textctrl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/controls_textctrl.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/controls_textctrl.cpp$(DependSuffix) -MM "controls/textctrl.cpp"

$(IntermediateDirectory)/controls_textctrl.cpp$(PreprocessSuffix): controls/textctrl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/controls_textctrl.cpp$(PreprocessSuffix) "controls/textctrl.cpp"

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxpad/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix): MainFrame.cpp $(IntermediateDirectory)/MainFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxpad/MainFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MainFrame.cpp$(DependSuffix): MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MainFrame.cpp$(DependSuffix) -MM "MainFrame.cpp"

$(IntermediateDirectory)/MainFrame.cpp$(PreprocessSuffix): MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MainFrame.cpp$(PreprocessSuffix) "MainFrame.cpp"

$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix): wxcrafter.cpp $(IntermediateDirectory)/wxcrafter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxpad/wxcrafter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxcrafter.cpp$(DependSuffix): wxcrafter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wxcrafter.cpp$(DependSuffix) -MM "wxcrafter.cpp"

$(IntermediateDirectory)/wxcrafter.cpp$(PreprocessSuffix): wxcrafter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxcrafter.cpp$(PreprocessSuffix) "wxcrafter.cpp"

$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix): wxcrafter_bitmaps.cpp $(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxpad/wxcrafter_bitmaps.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(DependSuffix): wxcrafter_bitmaps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(DependSuffix) -MM "wxcrafter_bitmaps.cpp"

$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(PreprocessSuffix): wxcrafter_bitmaps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(PreprocessSuffix) "wxcrafter_bitmaps.cpp"

$(IntermediateDirectory)/win_resources.rc$(ObjectSuffix): win_resources.rc
	$(RcCompilerName) -i "C:/Users/Robert/Documents/GitHub/vx.io/vxpad/win_resources.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/win_resources.rc$(ObjectSuffix) $(RcIncludePath)
$(IntermediateDirectory)/gui_vxAUIToolbarArt.cpp$(ObjectSuffix): src/gui/vxAUIToolbarArt.cpp $(IntermediateDirectory)/gui_vxAUIToolbarArt.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxpad/src/gui/vxAUIToolbarArt.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_vxAUIToolbarArt.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_vxAUIToolbarArt.cpp$(DependSuffix): src/gui/vxAUIToolbarArt.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_vxAUIToolbarArt.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_vxAUIToolbarArt.cpp$(DependSuffix) -MM "src/gui/vxAUIToolbarArt.cpp"

$(IntermediateDirectory)/gui_vxAUIToolbarArt.cpp$(PreprocessSuffix): src/gui/vxAUIToolbarArt.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_vxAUIToolbarArt.cpp$(PreprocessSuffix) "src/gui/vxAUIToolbarArt.cpp"

$(IntermediateDirectory)/gui_vxAuiTabArt.cpp$(ObjectSuffix): src/gui/vxAuiTabArt.cpp $(IntermediateDirectory)/gui_vxAuiTabArt.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxpad/src/gui/vxAuiTabArt.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_vxAuiTabArt.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_vxAuiTabArt.cpp$(DependSuffix): src/gui/vxAuiTabArt.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_vxAuiTabArt.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_vxAuiTabArt.cpp$(DependSuffix) -MM "src/gui/vxAuiTabArt.cpp"

$(IntermediateDirectory)/gui_vxAuiTabArt.cpp$(PreprocessSuffix): src/gui/vxAuiTabArt.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_vxAuiTabArt.cpp$(PreprocessSuffix) "src/gui/vxAuiTabArt.cpp"

$(IntermediateDirectory)/gui_Icon.cpp$(ObjectSuffix): src/gui/Icon.cpp $(IntermediateDirectory)/gui_Icon.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxpad/src/gui/Icon.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_Icon.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_Icon.cpp$(DependSuffix): src/gui/Icon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_Icon.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_Icon.cpp$(DependSuffix) -MM "src/gui/Icon.cpp"

$(IntermediateDirectory)/gui_Icon.cpp$(PreprocessSuffix): src/gui/Icon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_Icon.cpp$(PreprocessSuffix) "src/gui/Icon.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./bin/win/Debug/


