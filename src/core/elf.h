#ifndef ELF_H
#define ELF_H

typedef unsigned int elf_addr_t;
typedef unsigned short elf_half_t;
typedef unsigned int elf_offset_t;
typedef int elf_sword_t;
typedef unsigned int elf_word_t;
typedef unsigned char elf_byte_t;

enum ELF_TYPE {
    ELF_TYPE_NONE,
    ELF_TYPE_REL,
    ELF_TYPE_EXEC,
    ELF_TYPE_DYN,
    ELF_TYPE_CORE,
    ELF_TYPE_LOPROC = 0xff00,
    ELF_TYPE_HIPROC = 0xffff
};

enum ELF_MACHINE {
    ELF_MACHINE_NONE,
    ELF_MACHINE_M32,
    ELF_MACHINE_SPARC,
    ELF_MACHINE_386,
    ELF_MACHINE_68K,
    ELF_MACHINE_88K,
    ELF_MACHINE_860,
    ELF_MACHINE_MIPS,
};

enum ELF_VERSION {
    ELF_VERSION_NONE = 0,
    ELF_VERSION_CURRENT = 1
};

typedef enum ELF_TYPE elf_type_t;
typedef enum ELF_MACHINE elf_machine_t;
typedef enum ELF_VERSION elf_version_t;

typedef struct {
    elf_byte_t ident[16];
    elf_half_t type;
    elf_half_t machine;
    elf_word_t version;
    elf_addr_t entry;
    elf_offset_t phoff;
    elf_offset_t shoff;
    elf_word_t flags;
    elf_half_t ehsize;
    elf_half_t phentsize;
    elf_half_t phnum;
    elf_half_t shentsize;
    elf_half_t shnum;
    elf_half_t shstrndx;
} ELF_HEADER;

#endif