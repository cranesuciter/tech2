/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int open_file(char **argv)
{
    int fd;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("open :");
        return (EXIT_FAILURE);
    }
    return (fd);
}

void display_nm(Elf64_Shdr *sec, Elf64_Shdr *strsec, 
                Elf64_Sym *symtbl, char *symtbl_end)
{
    size_t i = 0;
    Elf64_Addr value;
    char *name;

    while (i < sec->sh_size / sizeof(*symtbl))
        {
            if (symtbl_end[symtbl[i].st_name] &&
             ELF64_ST_TYPE(symtbl[i].st_info) != STT_FILE) {
                value = symtbl[i].st_value;
                name = &symtbl_end[symtbl[i].st_name];
                printf("%x %s\n", value, name);
            }
            i++;
        }
}

int main(int argc, char **argv)
{
    int fd;
    int counter;
    int filesize;
    void *data;
    char *strtab;
    Elf64_Ehdr *elf;
    Elf64_Shdr *shdr;
    Elf64_Shdr *sec;
    Elf64_Shdr *strsec;
    Elf64_Sym *symtbl;
    char *symtbl_end;

    counter = 0;
    fd = open_file(argv);
    filesize = lseek(fd, 0, SEEK_END);
    data = mmap(NULL, filesize, PROT_READ,MAP_SHARED, fd, 0);
    if (data != NULL) 
    {
        elf = (Elf64_Ehdr *)data;
        shdr = (Elf64_Shdr *)(data + elf->e_shoff);
        strtab = (char *)(data + shdr[elf->e_shstrndx].sh_offset);   
        while(counter < elf->e_shnum)
        {
            if (!strcmp(&strtab[shdr[counter].sh_name], ".symtab"))
                sec = (Elf64_Shdr*)&shdr[counter];
            if (!strcmp(&strtab[shdr[counter].sh_name], ".strtab"))
                strsec = (Elf64_Shdr*)&shdr[counter];
            counter++;
        }
        symtbl = (Elf64_Sym*)(data + sec->sh_offset);
        symtbl_end = (char*)(data + strsec->sh_offset);
        display_nm(sec, strsec, symtbl, symtbl_end);
        return (EXIT_FAILURE);
    }    
}

void checkarg(int argc, char const *argv[])
{
    FILE * fichier = fopen("a.out", "r+b");

    if (argc == 1 && fichier == NULL) {
        printf("nm: << a.out >>: pas de tel fichier\n");
    }
}