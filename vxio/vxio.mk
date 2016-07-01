##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Win.Release
ProjectName            :=vxio
ConfigurationName      :=Win.Release
WorkspacePath          := "C:\Users\Robert\Documents\GitHub\vx.io"
ProjectPath            := "C:\Users\Robert\Documents\GitHub\vx.io\vxio"
IntermediateDirectory  :=./bin/win/Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Robert
Date                   :=02/07/2016
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
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="vxio.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := $(shell wx-config --rcflags)
RcCompilerName         :=C:/GNU/MinGW/bin/windres.exe
LinkOptions            :=  $(shell wx-config --libs) -mwindows
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
CXXFLAGS :=  -O2 -Wall $(shell wx-config --cflags) $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/GNU/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
WXWIN:=C:/wxWidgets
WXCFG:=gcc_dll/mswud
Objects0=$(IntermediateDirectory)/controls_vxTextCtrl.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) $(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) $(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) $(IntermediateDirectory)/win_resources.rc$(ObjectSuffix) $(IntermediateDirectory)/gui_vxAUIToolbarArt.cpp$(ObjectSuffix) $(IntermediateDirectory)/gui_vxAuiTabArt.cpp$(ObjectSuffix) $(IntermediateDirectory)/gui_Icon.cpp$(ObjectSuffix) $(IntermediateDirectory)/console_console.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/dirtree_dirtree.cpp$(ObjectSuffix) $(IntermediateDirectory)/find_find.cpp$(ObjectSuffix) $(IntermediateDirectory)/ntbk_OnCntrlCreate.cpp$(ObjectSuffix) $(IntermediateDirectory)/ntbk_methods_modifyText.cpp$(ObjectSuffix) $(IntermediateDirectory)/ntbk_methods_ntbkMisc.cpp$(ObjectSuffix) $(IntermediateDirectory)/ntbk_methods_fileIO.cpp$(ObjectSuffix) $(IntermediateDirectory)/ntbk_methods_system.cpp$(ObjectSuffix) $(IntermediateDirectory)/ntbk_methods_Help.cpp$(ObjectSuffix) 



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

PostBuild:
	@echo Executing Post Build commands ...
	cp -R $(ProjectDir)doc $(ProjectDir)$(OutDir)
	@echo Done

MakeIntermediateDirs:
	@$(MakeDirCommand) "./bin/win/Release"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./bin/win/Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/controls_vxTextCtrl.cpp$(ObjectSuffix): controls/vxTextCtrl.cpp $(IntermediateDirectory)/controls_vxTextCtrl.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxio/controls/vxTextCtrl.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/controls_vxTextCtrl.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/controls_vxTextCtrl.cpp$(DependSuffix): controls/vxTextCtrl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/controls_vxTextCtrl.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/controls_vxTextCtrl.cpp$(DependSuffix) -MM "controls/vxTextCtrl.cpp"

$(IntermediateDirectory)/controls_vxTextCtrl.cpp$(PreprocessSuffix): controls/vxTextCtrl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/controls_vxTextCtrl.cpp$(PreprocessSuffix) "controls/vxTextCtrl.cpp"

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxio/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix): MainFrame.cpp $(IntermediateDirectory)/MainFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxio/MainFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MainFrame.cpp$(DependSuffix): MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MainFrame.cpp$(DependSuffix) -MM "MainFrame.cpp"

$(IntermediateDirectory)/MainFrame.cpp$(PreprocessSuffix): MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MainFrame.cpp$(PreprocessSuffix) "MainFrame.cpp"

$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix): wxcrafter.cpp $(IntermediateDirectory)/wxcrafter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxio/wxcrafter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxcrafter.cpp$(DependSuffix): wxcrafter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wxcrafter.cpp$(DependSuffix) -MM "wxcrafter.cpp"

$(IntermediateDirectory)/wxcrafter.cpp$(PreprocessSuffix): wxcrafter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxcrafter.cpp$(PreprocessSuffix) "wxcrafter.cpp"

$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix): wxcrafter_bitmaps.cpp $(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxio/wxcrafter_bitmaps.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(DependSuffix): wxcrafter_bitmaps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(DependSuffix) -MM "wxcrafter_bitmaps.cpp"

$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(PreprocessSuffix): wxcrafter_bitmaps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(PreprocessSuffix) "wxcrafter_bitmaps.cpp"

$(IntermediateDirectory)/win_resources.rc$(ObjectSuffix): win_resources.rc
	$(RcCompilerName) -i "C:/Users/Robert/Documents/GitHub/vx.io/vxio/win_resources.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/win_resources.rc$(ObjectSuffix) $(RcIncludePath)
$(IntermediateDirectory)/gui_vxAUIToolbarArt.cpp$(ObjectSuffix): src/gui/vxAUIToolbarArt.cpp $(IntermediateDirectory)/gui_vxAUIToolbarArt.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxio/src/gui/vxAUIToolbarArt.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_vxAUIToolbarArt.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_vxAUIToolbarArt.cpp$(DependSuffix): src/gui/vxAUIToolbarArt.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_vxAUIToolbarArt.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_vxAUIToolbarArt.cpp$(DependSuffix) -MM "src/gui/vxAUIToolbarArt.cpp"

$(IntermediateDirectory)/gui_vxAUIToolbarArt.cpp$(PreprocessSuffix): src/gui/vxAUIToolbarArt.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_vxAUIToolbarArt.cpp$(PreprocessSuffix) "src/gui/vxAUIToolbarArt.cpp"

$(IntermediateDirectory)/gui_vxAuiTabArt.cpp$(ObjectSuffix): src/gui/vxAuiTabArt.cpp $(IntermediateDirectory)/gui_vxAuiTabArt.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxio/src/gui/vxAuiTabArt.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_vxAuiTabArt.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_vxAuiTabArt.cpp$(DependSuffix): src/gui/vxAuiTabArt.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_vxAuiTabArt.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_vxAuiTabArt.cpp$(DependSuffix) -MM "src/gui/vxAuiTabArt.cpp"

$(IntermediateDirectory)/gui_vxAuiTabArt.cpp$(PreprocessSuffix): src/gui/vxAuiTabArt.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_vxAuiTabArt.cpp$(PreprocessSuffix) "src/gui/vxAuiTabArt.cpp"

$(IntermediateDirectory)/gui_Icon.cpp$(ObjectSuffix): src/gui/Icon.cpp $(IntermediateDirectory)/gui_Icon.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxio/src/gui/Icon.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_Icon.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_Icon.cpp$(DependSuffix): src/gui/Icon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_Icon.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_Icon.cpp$(DependSuffix) -MM "src/gui/Icon.cpp"

$(IntermediateDirectory)/gui_Icon.cpp$(PreprocessSuffix): src/gui/Icon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_Icon.cpp$(PreprocessSuffix) "src/gui/Icon.cpp"

$(IntermediateDirectory)/console_console.cpp$(ObjectSuffix): src/console/console.cpp $(IntermediateDirectory)/console_console.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxio/src/console/console.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/console_console.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/console_console.cpp$(DependSuffix): src/console/console.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/console_console.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/console_console.cpp$(DependSuffix) -MM "src/console/console.cpp"

$(IntermediateDirectory)/console_console.cpp$(PreprocessSuffix): src/console/console.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/console_console.cpp$(PreprocessSuffix) "src/console/console.cpp"

$(IntermediateDirectory)/dirtree_dirtree.cpp$(ObjectSuffix): src/dirtree/dirtree.cpp $(IntermediateDirectory)/dirtree_dirtree.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxio/src/dirtree/dirtree.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/dirtree_dirtree.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/dirtree_dirtree.cpp$(DependSuffix): src/dirtree/dirtree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/dirtree_dirtree.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/dirtree_dirtree.cpp$(DependSuffix) -MM "src/dirtree/dirtree.cpp"

$(IntermediateDirectory)/dirtree_dirtree.cpp$(PreprocessSuffix): src/dirtree/dirtree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/dirtree_dirtree.cpp$(PreprocessSuffix) "src/dirtree/dirtree.cpp"

$(IntermediateDirectory)/find_find.cpp$(ObjectSuffix): src/find/find.cpp $(IntermediateDirectory)/find_find.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxio/src/find/find.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/find_find.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/find_find.cpp$(DependSuffix): src/find/find.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/find_find.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/find_find.cpp$(DependSuffix) -MM "src/find/find.cpp"

$(IntermediateDirectory)/find_find.cpp$(PreprocessSuffix): src/find/find.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/find_find.cpp$(PreprocessSuffix) "src/find/find.cpp"

$(IntermediateDirectory)/ntbk_OnCntrlCreate.cpp$(ObjectSuffix): src/ntbk/OnCntrlCreate.cpp $(IntermediateDirectory)/ntbk_OnCntrlCreate.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxio/src/ntbk/OnCntrlCreate.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ntbk_OnCntrlCreate.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ntbk_OnCntrlCreate.cpp$(DependSuffix): src/ntbk/OnCntrlCreate.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ntbk_OnCntrlCreate.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ntbk_OnCntrlCreate.cpp$(DependSuffix) -MM "src/ntbk/OnCntrlCreate.cpp"

$(IntermediateDirectory)/ntbk_OnCntrlCreate.cpp$(PreprocessSuffix): src/ntbk/OnCntrlCreate.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ntbk_OnCntrlCreate.cpp$(PreprocessSuffix) "src/ntbk/OnCntrlCreate.cpp"

$(IntermediateDirectory)/ntbk_methods_modifyText.cpp$(ObjectSuffix): src/ntbk/methods_modifyText.cpp $(IntermediateDirectory)/ntbk_methods_modifyText.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxio/src/ntbk/methods_modifyText.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ntbk_methods_modifyText.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ntbk_methods_modifyText.cpp$(DependSuffix): src/ntbk/methods_modifyText.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ntbk_methods_modifyText.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ntbk_methods_modifyText.cpp$(DependSuffix) -MM "src/ntbk/methods_modifyText.cpp"

$(IntermediateDirectory)/ntbk_methods_modifyText.cpp$(PreprocessSuffix): src/ntbk/methods_modifyText.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ntbk_methods_modifyText.cpp$(PreprocessSuffix) "src/ntbk/methods_modifyText.cpp"

$(IntermediateDirectory)/ntbk_methods_ntbkMisc.cpp$(ObjectSuffix): src/ntbk/methods_ntbkMisc.cpp $(IntermediateDirectory)/ntbk_methods_ntbkMisc.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxio/src/ntbk/methods_ntbkMisc.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ntbk_methods_ntbkMisc.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ntbk_methods_ntbkMisc.cpp$(DependSuffix): src/ntbk/methods_ntbkMisc.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ntbk_methods_ntbkMisc.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ntbk_methods_ntbkMisc.cpp$(DependSuffix) -MM "src/ntbk/methods_ntbkMisc.cpp"

$(IntermediateDirectory)/ntbk_methods_ntbkMisc.cpp$(PreprocessSuffix): src/ntbk/methods_ntbkMisc.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ntbk_methods_ntbkMisc.cpp$(PreprocessSuffix) "src/ntbk/methods_ntbkMisc.cpp"

$(IntermediateDirectory)/ntbk_methods_fileIO.cpp$(ObjectSuffix): src/ntbk/methods_fileIO.cpp $(IntermediateDirectory)/ntbk_methods_fileIO.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxio/src/ntbk/methods_fileIO.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ntbk_methods_fileIO.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ntbk_methods_fileIO.cpp$(DependSuffix): src/ntbk/methods_fileIO.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ntbk_methods_fileIO.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ntbk_methods_fileIO.cpp$(DependSuffix) -MM "src/ntbk/methods_fileIO.cpp"

$(IntermediateDirectory)/ntbk_methods_fileIO.cpp$(PreprocessSuffix): src/ntbk/methods_fileIO.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ntbk_methods_fileIO.cpp$(PreprocessSuffix) "src/ntbk/methods_fileIO.cpp"

$(IntermediateDirectory)/ntbk_methods_system.cpp$(ObjectSuffix): src/ntbk/methods_system.cpp $(IntermediateDirectory)/ntbk_methods_system.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxio/src/ntbk/methods_system.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ntbk_methods_system.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ntbk_methods_system.cpp$(DependSuffix): src/ntbk/methods_system.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ntbk_methods_system.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ntbk_methods_system.cpp$(DependSuffix) -MM "src/ntbk/methods_system.cpp"

$(IntermediateDirectory)/ntbk_methods_system.cpp$(PreprocessSuffix): src/ntbk/methods_system.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ntbk_methods_system.cpp$(PreprocessSuffix) "src/ntbk/methods_system.cpp"

$(IntermediateDirectory)/ntbk_methods_Help.cpp$(ObjectSuffix): src/ntbk/methods_Help.cpp $(IntermediateDirectory)/ntbk_methods_Help.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Robert/Documents/GitHub/vx.io/vxio/src/ntbk/methods_Help.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ntbk_methods_Help.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ntbk_methods_Help.cpp$(DependSuffix): src/ntbk/methods_Help.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ntbk_methods_Help.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ntbk_methods_Help.cpp$(DependSuffix) -MM "src/ntbk/methods_Help.cpp"

$(IntermediateDirectory)/ntbk_methods_Help.cpp$(PreprocessSuffix): src/ntbk/methods_Help.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ntbk_methods_Help.cpp$(PreprocessSuffix) "src/ntbk/methods_Help.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./bin/win/Release/


