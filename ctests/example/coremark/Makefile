RISCV_ARCH := rv32i
RISCV_ABI := ilp32
RISCV_MCMODEL := medlow

TARGET := coremark

C_SRCS := \
	core_list_join.c \
	core_main.c \
	core_matrix.c \
	core_state.c \
	core_util.c \
	core_portme.c \

CFLAGS := -O2 -fno-common -funroll-loops -finline-functions --param max-inline-insns-auto=20 -falign-functions=4 -falign-jumps=4 -falign-loops=4
CFLAGS += -DFLAGS_STR=\""$(CFLAGS)"\"
CFLAGS += -DPERFORMANCE_RUN=1

COMMON_DIR = ..
TOOLCHAIN_DIR = ../../..
include ../common.mk
