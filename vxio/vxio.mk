##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Tux.Debug
ProjectName            :=vxio
ConfigurationName      :=Tux.Debug
WorkspacePath          :=/home/tuxbox/Documents/code/vx.io
ProjectPath            :=/home/tuxbox/Documents/code/vx.io/vxio
IntermediateDirectory  :=./obj/tux/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=tuxbox
Date                   :=14/07/16
CodeLitePath           :=/home/tuxbox/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
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
OutputFile             :=./bin/tux/Debug/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="vxio.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  $(shell wx-config --libs --debug) `wx-config --libs --gl-libs` -lGL -lGLU -lglut -lstdc++ `wx-config --libs propgrid,core,base` `wx-config --cxxflags` `wx-config --libs` `wx-config --libs aui` `wx-config --libs std stc`
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
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(shell wx-config --cflags --debug) $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
LD_LIBRARY_PATH:=/home/tuxbox/Documents/code/iris-cad/lib/vxGUI/bin/linux/Debug:/home/tuxbox/Documents/code/iris-cad/lib/vxPad/bin/linux/Debug:/home/tuxbox/Documents/code/iris-cad/lib/vxOCC/bin/linux/Debug:/home/tuxbox/Documents/code/iris-cad/lib/vxICO/bin/linux/Debug
Objects0=$(IntermediateDirectory)/controls_vxTextCtrl.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) $(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) $(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) $(IntermediateDirectory)/lib_xmls_XMLSerialization.cpp$(ObjectSuffix) $(IntermediateDirectory)/lib_xmls_tinyxml2.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_gui_vxAUIToolbarArt.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_gui_vxAuiTabArt.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_gui_Icon.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/src_console_console.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_dirtree_dirtree.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_find_find.cpp$(ObjectSuffix) $(IntermediateDirectory)/FindReplace.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ntbk_OnCntrlCreate.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ntbk_methods_modifyText.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ntbk_methods_ntbkMisc.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ntbk_methods_fileIO.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ntbk_methods_system.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ntbk_methods_Help.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/src_ntbk_methods_settings.cpp$(ObjectSuffix) $(IntermediateDirectory)/SettingsDialog.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Settings.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_colorscheme_ColourScheme.cpp$(ObjectSuffix) 



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
	cp -R $(ProjectDir)doc $(ProjectDir)./bin/tux/Debug
	@echo Done

MakeIntermediateDirs:
	@test -d ./obj/tux/Debug || $(MakeDirCommand) ./obj/tux/Debug


$(IntermediateDirectory)/.d:
	@test -d ./obj/tux/Debug || $(MakeDirCommand) ./obj/tux/Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/controls_vxTextCtrl.cpp$(ObjectSuffix): controls/vxTextCtrl.cpp $(IntermediateDirectory)/controls_vxTextCtrl.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/controls/vxTextCtrl.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/controls_vxTextCtrl.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/controls_vxTextCtrl.cpp$(DependSuffix): controls/vxTextCtrl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/controls_vxTextCtrl.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/controls_vxTextCtrl.cpp$(DependSuffix) -MM "controls/vxTextCtrl.cpp"

$(IntermediateDirectory)/controls_vxTextCtrl.cpp$(PreprocessSuffix): controls/vxTextCtrl.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/controls_vxTextCtrl.cpp$(PreprocessSuffix) "controls/vxTextCtrl.cpp"

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix): MainFrame.cpp $(IntermediateDirectory)/MainFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/MainFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MainFrame.cpp$(DependSuffix): MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MainFrame.cpp$(DependSuffix) -MM "MainFrame.cpp"

$(IntermediateDirectory)/MainFrame.cpp$(PreprocessSuffix): MainFrame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MainFrame.cpp$(PreprocessSuffix) "MainFrame.cpp"

$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix): wxcrafter.cpp $(IntermediateDirectory)/wxcrafter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/wxcrafter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxcrafter.cpp$(DependSuffix): wxcrafter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wxcrafter.cpp$(DependSuffix) -MM "wxcrafter.cpp"

$(IntermediateDirectory)/wxcrafter.cpp$(PreprocessSuffix): wxcrafter.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxcrafter.cpp$(PreprocessSuffix) "wxcrafter.cpp"

$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix): wxcrafter_bitmaps.cpp $(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/wxcrafter_bitmaps.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(DependSuffix): wxcrafter_bitmaps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(DependSuffix) -MM "wxcrafter_bitmaps.cpp"

$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(PreprocessSuffix): wxcrafter_bitmaps.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(PreprocessSuffix) "wxcrafter_bitmaps.cpp"

$(IntermediateDirectory)/lib_xmls_XMLSerialization.cpp$(ObjectSuffix): lib/xmls/XMLSerialization.cpp $(IntermediateDirectory)/lib_xmls_XMLSerialization.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/lib/xmls/XMLSerialization.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lib_xmls_XMLSerialization.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lib_xmls_XMLSerialization.cpp$(DependSuffix): lib/xmls/XMLSerialization.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lib_xmls_XMLSerialization.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/lib_xmls_XMLSerialization.cpp$(DependSuffix) -MM "lib/xmls/XMLSerialization.cpp"

$(IntermediateDirectory)/lib_xmls_XMLSerialization.cpp$(PreprocessSuffix): lib/xmls/XMLSerialization.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lib_xmls_XMLSerialization.cpp$(PreprocessSuffix) "lib/xmls/XMLSerialization.cpp"

$(IntermediateDirectory)/lib_xmls_tinyxml2.cpp$(ObjectSuffix): lib/xmls/tinyxml2.cpp $(IntermediateDirectory)/lib_xmls_tinyxml2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/lib/xmls/tinyxml2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lib_xmls_tinyxml2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lib_xmls_tinyxml2.cpp$(DependSuffix): lib/xmls/tinyxml2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lib_xmls_tinyxml2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/lib_xmls_tinyxml2.cpp$(DependSuffix) -MM "lib/xmls/tinyxml2.cpp"

$(IntermediateDirectory)/lib_xmls_tinyxml2.cpp$(PreprocessSuffix): lib/xmls/tinyxml2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lib_xmls_tinyxml2.cpp$(PreprocessSuffix) "lib/xmls/tinyxml2.cpp"

$(IntermediateDirectory)/src_gui_vxAUIToolbarArt.cpp$(ObjectSuffix): src/gui/vxAUIToolbarArt.cpp $(IntermediateDirectory)/src_gui_vxAUIToolbarArt.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/src/gui/vxAUIToolbarArt.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_gui_vxAUIToolbarArt.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_gui_vxAUIToolbarArt.cpp$(DependSuffix): src/gui/vxAUIToolbarArt.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_gui_vxAUIToolbarArt.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_gui_vxAUIToolbarArt.cpp$(DependSuffix) -MM "src/gui/vxAUIToolbarArt.cpp"

$(IntermediateDirectory)/src_gui_vxAUIToolbarArt.cpp$(PreprocessSuffix): src/gui/vxAUIToolbarArt.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_gui_vxAUIToolbarArt.cpp$(PreprocessSuffix) "src/gui/vxAUIToolbarArt.cpp"

$(IntermediateDirectory)/src_gui_vxAuiTabArt.cpp$(ObjectSuffix): src/gui/vxAuiTabArt.cpp $(IntermediateDirectory)/src_gui_vxAuiTabArt.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/src/gui/vxAuiTabArt.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_gui_vxAuiTabArt.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_gui_vxAuiTabArt.cpp$(DependSuffix): src/gui/vxAuiTabArt.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_gui_vxAuiTabArt.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_gui_vxAuiTabArt.cpp$(DependSuffix) -MM "src/gui/vxAuiTabArt.cpp"

$(IntermediateDirectory)/src_gui_vxAuiTabArt.cpp$(PreprocessSuffix): src/gui/vxAuiTabArt.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_gui_vxAuiTabArt.cpp$(PreprocessSuffix) "src/gui/vxAuiTabArt.cpp"

$(IntermediateDirectory)/src_gui_Icon.cpp$(ObjectSuffix): src/gui/Icon.cpp $(IntermediateDirectory)/src_gui_Icon.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/src/gui/Icon.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_gui_Icon.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_gui_Icon.cpp$(DependSuffix): src/gui/Icon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_gui_Icon.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_gui_Icon.cpp$(DependSuffix) -MM "src/gui/Icon.cpp"

$(IntermediateDirectory)/src_gui_Icon.cpp$(PreprocessSuffix): src/gui/Icon.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_gui_Icon.cpp$(PreprocessSuffix) "src/gui/Icon.cpp"

$(IntermediateDirectory)/src_console_console.cpp$(ObjectSuffix): src/console/console.cpp $(IntermediateDirectory)/src_console_console.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/src/console/console.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_console_console.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_console_console.cpp$(DependSuffix): src/console/console.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_console_console.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_console_console.cpp$(DependSuffix) -MM "src/console/console.cpp"

$(IntermediateDirectory)/src_console_console.cpp$(PreprocessSuffix): src/console/console.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_console_console.cpp$(PreprocessSuffix) "src/console/console.cpp"

$(IntermediateDirectory)/src_dirtree_dirtree.cpp$(ObjectSuffix): src/dirtree/dirtree.cpp $(IntermediateDirectory)/src_dirtree_dirtree.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/src/dirtree/dirtree.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_dirtree_dirtree.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_dirtree_dirtree.cpp$(DependSuffix): src/dirtree/dirtree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_dirtree_dirtree.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_dirtree_dirtree.cpp$(DependSuffix) -MM "src/dirtree/dirtree.cpp"

$(IntermediateDirectory)/src_dirtree_dirtree.cpp$(PreprocessSuffix): src/dirtree/dirtree.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_dirtree_dirtree.cpp$(PreprocessSuffix) "src/dirtree/dirtree.cpp"

$(IntermediateDirectory)/src_find_find.cpp$(ObjectSuffix): src/find/find.cpp $(IntermediateDirectory)/src_find_find.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/src/find/find.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_find_find.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_find_find.cpp$(DependSuffix): src/find/find.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_find_find.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_find_find.cpp$(DependSuffix) -MM "src/find/find.cpp"

$(IntermediateDirectory)/src_find_find.cpp$(PreprocessSuffix): src/find/find.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_find_find.cpp$(PreprocessSuffix) "src/find/find.cpp"

$(IntermediateDirectory)/FindReplace.cpp$(ObjectSuffix): FindReplace.cpp $(IntermediateDirectory)/FindReplace.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/FindReplace.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/FindReplace.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/FindReplace.cpp$(DependSuffix): FindReplace.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/FindReplace.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/FindReplace.cpp$(DependSuffix) -MM "FindReplace.cpp"

$(IntermediateDirectory)/FindReplace.cpp$(PreprocessSuffix): FindReplace.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/FindReplace.cpp$(PreprocessSuffix) "FindReplace.cpp"

$(IntermediateDirectory)/src_ntbk_OnCntrlCreate.cpp$(ObjectSuffix): src/ntbk/OnCntrlCreate.cpp $(IntermediateDirectory)/src_ntbk_OnCntrlCreate.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/src/ntbk/OnCntrlCreate.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ntbk_OnCntrlCreate.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ntbk_OnCntrlCreate.cpp$(DependSuffix): src/ntbk/OnCntrlCreate.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ntbk_OnCntrlCreate.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ntbk_OnCntrlCreate.cpp$(DependSuffix) -MM "src/ntbk/OnCntrlCreate.cpp"

$(IntermediateDirectory)/src_ntbk_OnCntrlCreate.cpp$(PreprocessSuffix): src/ntbk/OnCntrlCreate.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ntbk_OnCntrlCreate.cpp$(PreprocessSuffix) "src/ntbk/OnCntrlCreate.cpp"

$(IntermediateDirectory)/src_ntbk_methods_modifyText.cpp$(ObjectSuffix): src/ntbk/methods_modifyText.cpp $(IntermediateDirectory)/src_ntbk_methods_modifyText.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/src/ntbk/methods_modifyText.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ntbk_methods_modifyText.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ntbk_methods_modifyText.cpp$(DependSuffix): src/ntbk/methods_modifyText.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ntbk_methods_modifyText.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ntbk_methods_modifyText.cpp$(DependSuffix) -MM "src/ntbk/methods_modifyText.cpp"

$(IntermediateDirectory)/src_ntbk_methods_modifyText.cpp$(PreprocessSuffix): src/ntbk/methods_modifyText.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ntbk_methods_modifyText.cpp$(PreprocessSuffix) "src/ntbk/methods_modifyText.cpp"

$(IntermediateDirectory)/src_ntbk_methods_ntbkMisc.cpp$(ObjectSuffix): src/ntbk/methods_ntbkMisc.cpp $(IntermediateDirectory)/src_ntbk_methods_ntbkMisc.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/src/ntbk/methods_ntbkMisc.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ntbk_methods_ntbkMisc.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ntbk_methods_ntbkMisc.cpp$(DependSuffix): src/ntbk/methods_ntbkMisc.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ntbk_methods_ntbkMisc.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ntbk_methods_ntbkMisc.cpp$(DependSuffix) -MM "src/ntbk/methods_ntbkMisc.cpp"

$(IntermediateDirectory)/src_ntbk_methods_ntbkMisc.cpp$(PreprocessSuffix): src/ntbk/methods_ntbkMisc.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ntbk_methods_ntbkMisc.cpp$(PreprocessSuffix) "src/ntbk/methods_ntbkMisc.cpp"

$(IntermediateDirectory)/src_ntbk_methods_fileIO.cpp$(ObjectSuffix): src/ntbk/methods_fileIO.cpp $(IntermediateDirectory)/src_ntbk_methods_fileIO.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/src/ntbk/methods_fileIO.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ntbk_methods_fileIO.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ntbk_methods_fileIO.cpp$(DependSuffix): src/ntbk/methods_fileIO.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ntbk_methods_fileIO.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ntbk_methods_fileIO.cpp$(DependSuffix) -MM "src/ntbk/methods_fileIO.cpp"

$(IntermediateDirectory)/src_ntbk_methods_fileIO.cpp$(PreprocessSuffix): src/ntbk/methods_fileIO.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ntbk_methods_fileIO.cpp$(PreprocessSuffix) "src/ntbk/methods_fileIO.cpp"

$(IntermediateDirectory)/src_ntbk_methods_system.cpp$(ObjectSuffix): src/ntbk/methods_system.cpp $(IntermediateDirectory)/src_ntbk_methods_system.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/src/ntbk/methods_system.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ntbk_methods_system.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ntbk_methods_system.cpp$(DependSuffix): src/ntbk/methods_system.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ntbk_methods_system.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ntbk_methods_system.cpp$(DependSuffix) -MM "src/ntbk/methods_system.cpp"

$(IntermediateDirectory)/src_ntbk_methods_system.cpp$(PreprocessSuffix): src/ntbk/methods_system.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ntbk_methods_system.cpp$(PreprocessSuffix) "src/ntbk/methods_system.cpp"

$(IntermediateDirectory)/src_ntbk_methods_Help.cpp$(ObjectSuffix): src/ntbk/methods_Help.cpp $(IntermediateDirectory)/src_ntbk_methods_Help.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/src/ntbk/methods_Help.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ntbk_methods_Help.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ntbk_methods_Help.cpp$(DependSuffix): src/ntbk/methods_Help.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ntbk_methods_Help.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ntbk_methods_Help.cpp$(DependSuffix) -MM "src/ntbk/methods_Help.cpp"

$(IntermediateDirectory)/src_ntbk_methods_Help.cpp$(PreprocessSuffix): src/ntbk/methods_Help.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ntbk_methods_Help.cpp$(PreprocessSuffix) "src/ntbk/methods_Help.cpp"

$(IntermediateDirectory)/src_ntbk_methods_settings.cpp$(ObjectSuffix): src/ntbk/methods_settings.cpp $(IntermediateDirectory)/src_ntbk_methods_settings.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/src/ntbk/methods_settings.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ntbk_methods_settings.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ntbk_methods_settings.cpp$(DependSuffix): src/ntbk/methods_settings.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ntbk_methods_settings.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ntbk_methods_settings.cpp$(DependSuffix) -MM "src/ntbk/methods_settings.cpp"

$(IntermediateDirectory)/src_ntbk_methods_settings.cpp$(PreprocessSuffix): src/ntbk/methods_settings.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ntbk_methods_settings.cpp$(PreprocessSuffix) "src/ntbk/methods_settings.cpp"

$(IntermediateDirectory)/SettingsDialog.cpp$(ObjectSuffix): SettingsDialog.cpp $(IntermediateDirectory)/SettingsDialog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/SettingsDialog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SettingsDialog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SettingsDialog.cpp$(DependSuffix): SettingsDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SettingsDialog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SettingsDialog.cpp$(DependSuffix) -MM "SettingsDialog.cpp"

$(IntermediateDirectory)/SettingsDialog.cpp$(PreprocessSuffix): SettingsDialog.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SettingsDialog.cpp$(PreprocessSuffix) "SettingsDialog.cpp"

$(IntermediateDirectory)/src_Settings.cpp$(ObjectSuffix): src/Settings.cpp $(IntermediateDirectory)/src_Settings.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/src/Settings.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Settings.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Settings.cpp$(DependSuffix): src/Settings.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Settings.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Settings.cpp$(DependSuffix) -MM "src/Settings.cpp"

$(IntermediateDirectory)/src_Settings.cpp$(PreprocessSuffix): src/Settings.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Settings.cpp$(PreprocessSuffix) "src/Settings.cpp"

$(IntermediateDirectory)/src_colorscheme_ColourScheme.cpp$(ObjectSuffix): src/colorscheme/ColourScheme.cpp $(IntermediateDirectory)/src_colorscheme_ColourScheme.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tuxbox/Documents/code/vx.io/vxio/src/colorscheme/ColourScheme.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_colorscheme_ColourScheme.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_colorscheme_ColourScheme.cpp$(DependSuffix): src/colorscheme/ColourScheme.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_colorscheme_ColourScheme.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_colorscheme_ColourScheme.cpp$(DependSuffix) -MM "src/colorscheme/ColourScheme.cpp"

$(IntermediateDirectory)/src_colorscheme_ColourScheme.cpp$(PreprocessSuffix): src/colorscheme/ColourScheme.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_colorscheme_ColourScheme.cpp$(PreprocessSuffix) "src/colorscheme/ColourScheme.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./obj/tux/Debug/


