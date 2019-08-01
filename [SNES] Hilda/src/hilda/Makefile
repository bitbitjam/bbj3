# path to snesdev root directory (for emulators, devkitsnes, libsnes)
export DEVKITSNES := /c/snesdev

# path to devkitsnes root directory for compiler
export DEVKIT65XX := /c/snesdev/devkitsnes

#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------

ifeq ($(strip $(DEVKIT65XX)),)
$(error "Please set DEVKIT65XX in your environment. export DEVKIT65XX=<path to>devkit65XX")
endif

include $(DEVKIT65XX)/snes_rules

#---------------------------------------------------------------------------------
# TARGET is the name of the output
# BUILD is the directory where object files & intermediate files will be placed
# SOURCES is a list of directories containing source code
# INCLUDES is a list of directories containing extra header files
#---------------------------------------------------------------------------------
TARGET		:=	$(shell basename $(CURDIR))
SOURCES		:=	.

#---------------------------------------------------------------------------------
# options for code generation
#---------------------------------------------------------------------------------
CFLAGS	+=	$(INCLUDE) 

#---------------------------------------------------------------------------------
# list of directories containing libraries, this must be the top level containing
# include and lib
#---------------------------------------------------------------------------------
LIBDIRS	:=	$(PVSNESLIB)
LIBOBJS +:=	
 
export OUTPUT	:=	$(CURDIR)/$(TARGET)
 
CFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
SFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.asm)))

export AUDIOFILES :=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.it)))
ifneq ($(AUDIOFILES),)
ifeq ($(wildcard soundbank.asm),)
	SFILES		:=	soundbank.asm $(SFILES)
endif
endif
 
#---------------------------------------------------------------------------------

export OFILES	:=	$(BINFILES:.bin=.obj) $(CFILES:.c=.obj) $(SFILES:.asm=.obj)
 
export INCLUDE	:=	$(foreach dir,$(INCLUDES),-I$(CURDIR)/$(dir)) \
					$(foreach dir,$(LIBDIRS),-I$(dir)/include) \
					-I$(CURDIR)/$(BUILD)

SMCONVFLAGS	:= -l -s -o soundbank -v -b 5
GTITLE 		:= -ht"$(TARGET)"
 
.PHONY: bitmaps all
 
#---------------------------------------------------------------------------------
all	:	bitmaps $(OUTPUT).sfc
	$(SNTOOLS) -hi! $(GTITLE) $(TARGET).sfc

clean:
	@echo clean ...
	@rm -f $(OFILES) $(TARGET).sfc  *.pic *.pal *.map *.clm
	
soundclean:
	@echo Sound clean ...
	@rm -f *.bnk soundbank.asm soundbank.h
#

#--------------------------------------------------------------------------------- SOUND
#---------------------------------------------------------------------------------
soundbank.asm : $(AUDIOFILES)
	@echo Compiling Soundbank ... 
	@$(SMCONV) $(SMCONVFLAGS) $^
#--------------------------------------------------------------------------------- PICTURES
#General Font
font.pic: font.bmp
	@echo convert font with no tile reduction ... $(notdir $@)
	$(GFXCONV) -pc4 -n -gs8 -po2 -pe1 -mR! -m $<
#Player graphic
player.pic: player.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -gs32 -pc16 -po256 -n $<
	
#Splash background
splash.pic: splash.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -pr -pc16 -n -gs16 -pe0 -fbmp -mp $<
	
#Title background
title.pic: title.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -pr -pc16 -n -gs8 -pe1 -fbmp -m $<
#Title foreground
title-1.pic: title-1.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -pr -pc16 -n -gs8 -pe2 -fbmp -m $<

#Background
background.pic: background.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -pr -pc16 -n -gs8 -pe2 -fbmp -m $<
#Room1
room1.pic: room1.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -pr -pc16 -n -gs8 -pe1 -fbmp -m $<
room1_col.clm: room1_col.bmp
	@echo convert collision map ... $(notdir $@)
	$(GFXCONV) -pr -pc16 -n -gs8 -mc $<
	
#Room2
room2.pic: room2.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -pr -pc16 -n -gs8 -pe1 -fbmp -m $<
	#$(GFXCONV) -pc16 -n -gs8 -pe2 -fbmp -m $<
room2_col.clm: room2_col.bmp
	@echo convert collision map ... $(notdir $@)
	$(GFXCONV) -pr -pc16 -n -gs8 -mc $<
	
#Room3
room3.pic: room3.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -pr -pc16 -n -gs8 -pe1 -fbmp -m $<
room3_col.clm: room3_col.bmp
	@echo convert collision map ... $(notdir $@)
	$(GFXCONV) -pr -pc16 -n -gs8 -mc $<
	
#Room4
room4.pic: room4.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -pr -pc16 -n -gs8 -pe1 -fbmp -m $<
room4_col.clm: room4_col.bmp
	@echo convert collision map ... $(notdir $@)
	$(GFXCONV) -pr -pc16 -n -gs8 -mc $<
	
#Room5
room5.pic: room5.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -pr -pc16 -n -gs8 -pe1 -fbmp -m $<
room5_col.clm: room5_col.bmp
	@echo convert collision map ... $(notdir $@)
	$(GFXCONV) -pr -pc16 -n -gs8 -mc $<
	
#Room6
room6.pic: room6.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -pr -pc16 -n -gs8 -pe2 -fbmp -m $<
room6_col.clm: room6_col.bmp
	@echo convert collision map ... $(notdir $@)
	$(GFXCONV) -pr -pc16 -n -gs8 -mc $<

#accept.brr cancel.brr select.brr enistudios.brr footstep.brr jump.brr attack.brr hurt.brr
bitmaps : soundbank.asm font.pic splash.pic player.pic background.pic room1.pic room1_col.clm room2.pic room2_col.clm room3.pic room3_col.clm room4.pic room4_col.clm room5.pic room5_col.clm room6.pic room6_col.clm title.pic title-1.pic
#---------------------------------------------------------------------------------
$(OUTPUT).sfc	: $(OFILES)
