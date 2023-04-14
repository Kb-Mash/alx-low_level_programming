#include "main.h"

/**
 * _magic - prints ELF magic
 * @buffer: pointer to an array containing the ELF magic numbers
 */
void _magic(unsigned char *buffer)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", buffer[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * _class - prints ELF class
 * @buffer: pointer to an array containing the ELF class
 */
void _class(unsigned char *buffer)
{
	printf("  Class:                             ");

	switch (buffer[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", buffer[EI_CLASS]);
	}
}

/**
 * _data - prints ELF data
 * @buffer: pointer to an array containing the ELF class.
 */
void _data(unsigned char *buffer)
{
	printf("  Data:                              ");

	switch (buffer[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", buffer[EI_CLASS]);
	}
}

/**
 * _version - prints ELF version
 * @buffer: pointer to an array containing the ELF version
 */
void _version(const unsigned char *buffer)
{
	printf("  Version:                           %d",
			buffer[EI_VERSION]);

	if (buffer[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * _osabi - prints ELF OS/ABI
 * @buffer: pointer to an array containing the ELF version
 */
void _osabi(const unsigned char *buffer)
{
	const char *osTable[19] = {
		"UNIX - System V",
		"UNIX - HP-UX",
		"UNIX - NetBSD",
		"UNIX - GNU",
		"<unknown: 4>",
		"<unknown: 5>",
		"UNIX - Solaris",
		"UNIX - AIX",
		"UNIX - IRIX",
		"UNIX - FreeBSD",
		"UNIX - Tru64",
		"Novell - Modesto",
		"UNIX - OpenBSD",
		"VMS - OpenVMS",
		"HP - Non-Stop Kernel",
		"AROS",
		"FenixOS",
		"Nuxi CloudABI",
		"Stratus Technologies OpenVOS"
	};

	printf("  OS/ABI:                            ");

	if (buffer[EI_OSABI] < 19)
		printf("%s\n", osTable[(unsigned int) buffer[EI_OSABI]]);
	else
		printf("<unknown: %x>\n", buffer[EI_OSABI]);
}

/**
 * _abi - prints ELF ABI version
 * @buffer: pointer to an array containing the ELF ABI version.
 */
void _abi(unsigned char *buffer)
{
	printf("  ABI Version:                       %d\n",
	       buffer[EI_ABIVERSION]);
}

/**
 * _type - prints ELF type
 * @type: ELF type
 * @buffer: pointer to an array containing the ELF class.
 */
void _type(unsigned int type, unsigned char *buffer)
{
	if (buffer[EI_DATA] == ELFDATA2MSB)
		type >>= 8;

	printf("  Type:                              ");

	switch (type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", type);
	}
}

/**
 * _entry - prints entry point address
 * @entry: address of the ELF entry point.
 * @buffer: pointer to string containing address
 */
void _entry(unsigned long int entry, unsigned char *buffer)
{
	printf("  Entry point address:               ");

	if (buffer[EI_DATA] == ELFDATA2MSB)
	{
		entry = ((entry << 8) & 0xFF00FF00) |
			  ((entry >> 8) & 0xFF00FF);
		entry = (entry << 16) | (entry >> 16);
	}

	if (buffer[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entry);

	else
		printf("%#lx\n", entry);
}

/**
 * _close - close ELF file
 * @fd: file descriptor to close
 */
void _close(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd);
		exit(98);
	}
}

/**
 * if_elf - checks to see if file is an ELF file.
 * @buffer: ELF header
 */
void if_elf(unsigned char *buffer)
{
	for (int i = 0; i < 4; i++)
	{
		if (buffer[i] != 127 &&
		    buffer[i] != 'E' &&
		    buffer[i] != 'L' &&
		    buffer[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * main - displays the information contained in
 * the ELF header at the start of an ELF file
 * @argc: number of arguments
 * @argv: array of pointers pointing to the arguments
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);

	Elf64_Ehdr *elf_header;
	int fd, r;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	elf_header = malloc(sizeof(Elf64_Ehdr));
	if (elf_header == NULL)
	{
		_close(fd);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(fd, elf_header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(elf_header);
		_close(fd);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	if_elf(elf_header->e_ident);
	printf("ELF Header:\n");
	_magic(elf_header->e_ident);
	_class(elf_header->e_ident);
	_data(elf_header->e_ident);
	_version(elf_header->e_ident);
	_osabi(elf_header->e_ident);
	_abi(elf_header->e_ident);
	_type(elf_header->e_type, elf_header->e_ident);
	_entry(elf_header->e_entry, elf_header->e_ident);

	free(elf_header);
	_close(fd);
	return (0);
}
