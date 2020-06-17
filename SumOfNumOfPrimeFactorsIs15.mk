##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=SumOfNumOfPrimeFactorsIs15
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/uzi/Projects/github/factoring
ProjectPath            :=/home/uzi/Projects/github/factoring/SumOfNumOfPrimeFactorsIs15
IntermediateDirectory  :=../build-$(ConfigurationName)/SumOfNumOfPrimeFactorsIs15
OutDir                 :=../build-$(ConfigurationName)/SumOfNumOfPrimeFactorsIs15
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Uzi Cohen
Date                   :=17/06/20
CodeLitePath           :=/home/uzi/.codelite
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
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
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
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/SumOfNumOfPrimeFactorsIs15/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/SumOfNumOfPrimeFactorsIs15/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/SumOfNumOfPrimeFactorsIs15"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/SumOfNumOfPrimeFactorsIs15"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/SumOfNumOfPrimeFactorsIs15/.d:
	@mkdir -p "../build-$(ConfigurationName)/SumOfNumOfPrimeFactorsIs15"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/SumOfNumOfPrimeFactorsIs15/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/SumOfNumOfPrimeFactorsIs15/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/uzi/Projects/github/factoring/SumOfNumOfPrimeFactorsIs15/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/SumOfNumOfPrimeFactorsIs15/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/SumOfNumOfPrimeFactorsIs15/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/SumOfNumOfPrimeFactorsIs15/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/SumOfNumOfPrimeFactorsIs15/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/SumOfNumOfPrimeFactorsIs15/main.cpp$(PreprocessSuffix) main.cpp


-include ../build-$(ConfigurationName)/SumOfNumOfPrimeFactorsIs15//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


