#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin_4.x-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1168552714/id_factory.o \
	${OBJECTDIR}/component.o \
	${OBJECTDIR}/entity.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lib-crucible-engine-core.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lib-crucible-engine-core.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lib-crucible-engine-core.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lib-crucible-engine-core.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lib-crucible-engine-core.a

${OBJECTDIR}/_ext/1168552714/id_factory.o: /cygdrive/C/Users/mlynam/Documents/NetBeansProjects/crucible-engine/core/id_factory.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1168552714
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1168552714/id_factory.o /cygdrive/C/Users/mlynam/Documents/NetBeansProjects/crucible-engine/core/id_factory.cpp

${OBJECTDIR}/component.o: component.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/component.o component.cpp

${OBJECTDIR}/entity.o: entity.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/entity.o entity.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/test-entity.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -l-crucible-engine-core -L/cygdrive/C/Users/mlynam/Documents/NetBeansProjects/crucible-engine/core/dist/Debug/Cygwin_4.x-Windows 


${TESTDIR}/tests/test-entity.o: tests/test-entity.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/cygdrive/C/Users/mlynam/Documents/NetBeansProjects/crucible-engine/core -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/test-entity.o tests/test-entity.cpp


${OBJECTDIR}/_ext/1168552714/id_factory_nomain.o: ${OBJECTDIR}/_ext/1168552714/id_factory.o /cygdrive/C/Users/mlynam/Documents/NetBeansProjects/crucible-engine/core/id_factory.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1168552714
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1168552714/id_factory.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1168552714/id_factory_nomain.o /cygdrive/C/Users/mlynam/Documents/NetBeansProjects/crucible-engine/core/id_factory.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1168552714/id_factory.o ${OBJECTDIR}/_ext/1168552714/id_factory_nomain.o;\
	fi

${OBJECTDIR}/component_nomain.o: ${OBJECTDIR}/component.o component.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/component.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/component_nomain.o component.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/component.o ${OBJECTDIR}/component_nomain.o;\
	fi

${OBJECTDIR}/entity_nomain.o: ${OBJECTDIR}/entity.o entity.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/entity.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/entity_nomain.o entity.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/entity.o ${OBJECTDIR}/entity_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lib-crucible-engine-core.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
