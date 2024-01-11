/*
Copyright (c) the Selfie Project authors. All rights reserved.
Please see the AUTHORS file for details. Use of this source code is
governed by a BSD license that can be found in the LICENSE file.

Selfie is a project of the Computational Systems Group at the
Department of Computer Sciences of the University of Salzburg
in Austria. For further information and code please refer to:

selfie.cs.uni-salzburg.at

Rotor is a tool for bit-precise reasoning about RISC-V machines
using BTOR2 as intermediate modeling format.
*/

// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~
// -----------------------------------------------------------------
// -----------------------     M O D E L     -----------------------
// -----------------------------------------------------------------
// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~

uint64_t* allocate_line() {
  return smalloc(5 * sizeof(uint64_t*) + 2 * sizeof(char*) + 2 * sizeof(uint64_t));
}

uint64_t  get_nid(uint64_t* line)     { return *line; }
char*     get_op(uint64_t* line)      { return (char*)     *(line + 1); }
uint64_t* get_sid(uint64_t* line)     { return (uint64_t*) *(line + 2); }
uint64_t* get_arg1(uint64_t* line)    { return (uint64_t*) *(line + 3); }
uint64_t* get_arg2(uint64_t* line)    { return (uint64_t*) *(line + 4); }
uint64_t* get_arg3(uint64_t* line)    { return (uint64_t*) *(line + 5); }
char*     get_comment(uint64_t* line) { return (char*)     *(line + 6); }
uint64_t  get_reuse(uint64_t* line)   { return (uint64_t)  *(line + 7); }
uint64_t* get_pred(uint64_t* line)    { return (uint64_t*) *(line + 8); }

void set_nid(uint64_t* line, uint64_t nid)      { *line       = nid; }
void set_op(uint64_t* line, char* op)           { *(line + 1) = (uint64_t) op; }
void set_sid(uint64_t* line, uint64_t* sid)     { *(line + 2) = (uint64_t) sid; }
void set_arg1(uint64_t* line, uint64_t* arg1)   { *(line + 3) = (uint64_t) arg1; }
void set_arg2(uint64_t* line, uint64_t* arg2)   { *(line + 4) = (uint64_t) arg2; }
void set_arg3(uint64_t* line, uint64_t* arg3)   { *(line + 5) = (uint64_t) arg3; }
void set_comment(uint64_t* line, char* comment) { *(line + 6) = (uint64_t) comment; }
void set_reuse(uint64_t* line, uint64_t reuse)  { *(line + 7) = reuse; }
void set_pred(uint64_t* line, uint64_t* pred)   { *(line + 8) = (uint64_t) pred; }

uint64_t  are_lines_equal(uint64_t* left_line, uint64_t* right_line);
uint64_t* find_equal_line(uint64_t* line);

uint64_t* new_line(char* op, uint64_t* sid, uint64_t* arg1, uint64_t* arg2, uint64_t* arg3, char* comment);

uint64_t* new_bitvec(uint64_t size_in_bits, char* comment);
uint64_t* new_array(uint64_t* size_sid, uint64_t* element_sid, char* comment);

uint64_t* new_constant(char* op, uint64_t* sid, uint64_t constant, uint64_t digits, char* comment);
uint64_t* new_input(char* op, uint64_t* sid, char* symbol, char* comment);

uint64_t* new_ext(char* op, uint64_t* sid, uint64_t* value_nid, uint64_t w, char* comment);
uint64_t* new_slice(uint64_t* sid, uint64_t* value_nid, uint64_t u, uint64_t l, char* comment);

uint64_t* new_unary(char* op, uint64_t* sid, uint64_t* value_nid, char* comment);
uint64_t* new_unary_boolean(char* op, uint64_t* value_nid, char* comment);
uint64_t* new_binary(char* op, uint64_t* sid, uint64_t* left_nid, uint64_t* right_nid, char* comment);
uint64_t* new_binary_boolean(char* op, uint64_t* left_nid, uint64_t* right_nid, char* comment);
uint64_t* new_ternary(char* op, uint64_t* sid, uint64_t* first_nid, uint64_t* second_nid, uint64_t* third_nid, char* comment);

uint64_t* new_property(char* op, uint64_t* condition_nid, char* symbol, char* comment);

void print_nid(uint64_t nid, uint64_t* line);

uint64_t print_sort(uint64_t nid, uint64_t* line);
uint64_t print_constant(uint64_t nid, uint64_t* line);
uint64_t print_input(uint64_t nid, uint64_t* line);

uint64_t print_ext(uint64_t nid, uint64_t* line);
uint64_t print_slice(uint64_t nid, uint64_t* line);

uint64_t print_unary_op(uint64_t nid, uint64_t* line);
uint64_t print_binary_op(uint64_t nid, uint64_t* line);
uint64_t print_ternary_op(uint64_t nid, uint64_t* line);

uint64_t print_constraint(uint64_t nid, uint64_t* line);

void print_comment(uint64_t* line);

uint64_t is_constant_op(char* op);
uint64_t is_input_op(char* op);
uint64_t is_unary_op(char* op);

uint64_t print_referenced_line(uint64_t nid, uint64_t* line);

void print_line(uint64_t* line);
void print_break(char* comment);
void print_aligned_break(char* comment, uint64_t alignment);

char* format_comment(char* comment, uint64_t value);

char* format_binary(uint64_t value, uint64_t alignment);
char* format_decimal(uint64_t value);
char* format_hexadecimal(uint64_t value);

char* format_comment_binary(char* comment, uint64_t value);

// ------------------------ GLOBAL CONSTANTS -----------------------

uint64_t* UNUSED    = (uint64_t*) 0;
char*     NOCOMMENT = (char*) 0;

char* BITVEC = (char*) 0;
char* ARRAY  = (char*) 0;

char* OP_SORT = (char*) 0;

char* OP_CONST  = (char*) 0;
char* OP_CONSTD = (char*) 0;
char* OP_CONSTH = (char*) 0;
char* OP_INPUT  = (char*) 0;
char* OP_STATE  = (char*) 0;

char* OP_INIT  = (char*) 0;
char* OP_NEXT  = (char*) 0;

char* OP_SEXT  = (char*) 0;
char* OP_UEXT  = (char*) 0;
char* OP_SLICE = (char*) 0;

char* OP_NOT = (char*) 0;
char* OP_INC = (char*) 0;
char* OP_DEC = (char*) 0;
char* OP_NEG = (char*) 0;

char* OP_EQ   = (char*) 0;
char* OP_NEQ  = (char*) 0;
char* OP_SGT  = (char*) 0;
char* OP_UGT  = (char*) 0;
char* OP_SGTE = (char*) 0;
char* OP_UGTE = (char*) 0;
char* OP_SLT  = (char*) 0;
char* OP_ULT  = (char*) 0;
char* OP_SLTE = (char*) 0;
char* OP_ULTE = (char*) 0;

char* OP_AND = (char*) 0;
char* OP_OR  = (char*) 0;
char* OP_XOR = (char*) 0;

char* OP_SLL = (char*) 0;
char* OP_SRL = (char*) 0;
char* OP_SRA = (char*) 0;

char* OP_ADD  = (char*) 0;
char* OP_SUB  = (char*) 0;
char* OP_MUL  = (char*) 0;
char* OP_SDIV = (char*) 0;
char* OP_UDIV = (char*) 0;
char* OP_SREM = (char*) 0;
char* OP_UREM = (char*) 0;

char* OP_CONCAT = (char*) 0;
char* OP_READ   = (char*) 0;

char* OP_ITE   = (char*) 0;
char* OP_WRITE = (char*) 0;

char* OP_BAD        = (char*) 0;
char* OP_CONSTRAINT = (char*) 0;

// ------------------------ GLOBAL VARIABLES -----------------------

uint64_t* last_line   = (uint64_t*) 0;
uint64_t* unused_line = (uint64_t*) 0;

uint64_t number_of_lines = 0;

uint64_t current_nid = 1; // first nid is 1

// ------------------------- INITIALIZATION ------------------------

void init_model() {
  BITVEC = "bitvec";
  ARRAY  = "array";

  OP_SORT = "sort";

  OP_CONST  = "const";
  OP_CONSTD = "constd";
  OP_CONSTH = "consth";
  OP_INPUT  = "input";
  OP_STATE  = "state";

  OP_INIT  = "init";
  OP_NEXT  = "next";

  OP_SEXT  = "sext";
  OP_UEXT  = "uext";
  OP_SLICE = "slice";

  OP_NOT = "not";
  OP_INC = "inc";
  OP_DEC = "dec";
  OP_NEG = "neg";

  OP_EQ   = "eq";
  OP_NEQ  = "neq";
  OP_SGT  = "sgt";
  OP_UGT  = "ugt";
  OP_SGTE = "sgte";
  OP_UGTE = "ugte";
  OP_SLT  = "slt";
  OP_ULT  = "ult";
  OP_SLTE = "slte";
  OP_ULTE = "ulte";

  OP_AND = "and";
  OP_OR  = "or";
  OP_XOR = "xor";

  OP_SLL = "sll";
  OP_SRL = "srl";
  OP_SRA = "sra";

  OP_ADD  = "add";
  OP_SUB  = "sub";
  OP_MUL  = "mul";
  OP_SDIV = "sdiv";
  OP_UDIV = "udiv";
  OP_SREM = "srem";
  OP_UREM = "urem";

  OP_CONCAT = "concat";
  OP_READ   = "read";

  OP_ITE   = "ite";
  OP_WRITE = "write";

  OP_BAD        = "bad";
  OP_CONSTRAINT = "constraint";
}

// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~
// -----------------------------------------------------------------
// -------------------     I N T E R F A C E     -------------------
// -----------------------------------------------------------------
// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~

void print_interface_sorts();

// ------------------------ GLOBAL CONSTANTS -----------------------

uint64_t* SID_BOOLEAN = (uint64_t*) 0;

uint64_t* NID_FALSE = (uint64_t*) 0;
uint64_t* NID_TRUE  = (uint64_t*) 1;

uint64_t* SID_BYTE = (uint64_t*) 0;

uint64_t* NID_BYTE_0 = (uint64_t*) 0;

uint64_t* SID_HALF_WORD = (uint64_t*) 0;

uint64_t* SID_SINGLE_WORD = (uint64_t*) 0;

uint64_t* NID_SINGLE_WORD_0 = (uint64_t*) 0;
uint64_t* NID_SINGLE_WORD_1 = (uint64_t*) 0;
uint64_t* NID_SINGLE_WORD_2 = (uint64_t*) 0;
uint64_t* NID_SINGLE_WORD_3 = (uint64_t*) 0;
uint64_t* NID_SINGLE_WORD_4 = (uint64_t*) 0;
uint64_t* NID_SINGLE_WORD_5 = (uint64_t*) 0;
uint64_t* NID_SINGLE_WORD_6 = (uint64_t*) 0;
uint64_t* NID_SINGLE_WORD_7 = (uint64_t*) 0;
uint64_t* NID_SINGLE_WORD_8 = (uint64_t*) 0;

uint64_t* NID_SINGLE_WORD_MINUS_1 = (uint64_t*) 0;

uint64_t* SID_DOUBLE_WORD = (uint64_t*) 0;

uint64_t* NID_DOUBLE_WORD_0 = (uint64_t*) 0;
uint64_t* NID_DOUBLE_WORD_1 = (uint64_t*) 0;
uint64_t* NID_DOUBLE_WORD_2 = (uint64_t*) 0;
uint64_t* NID_DOUBLE_WORD_3 = (uint64_t*) 0;
uint64_t* NID_DOUBLE_WORD_4 = (uint64_t*) 0;
uint64_t* NID_DOUBLE_WORD_5 = (uint64_t*) 0;
uint64_t* NID_DOUBLE_WORD_6 = (uint64_t*) 0;
uint64_t* NID_DOUBLE_WORD_7 = (uint64_t*) 0;
uint64_t* NID_DOUBLE_WORD_8 = (uint64_t*) 0;

uint64_t* NID_DOUBLE_WORD_MINUS_1 = (uint64_t*) 0;

uint64_t* SID_MACHINE_WORD = (uint64_t*) 0;

uint64_t* NID_MACHINE_WORD_0 = (uint64_t*) 0;
uint64_t* NID_MACHINE_WORD_1 = (uint64_t*) 0;
uint64_t* NID_MACHINE_WORD_2 = (uint64_t*) 0;
uint64_t* NID_MACHINE_WORD_3 = (uint64_t*) 0;
uint64_t* NID_MACHINE_WORD_4 = (uint64_t*) 0;
uint64_t* NID_MACHINE_WORD_5 = (uint64_t*) 0;
uint64_t* NID_MACHINE_WORD_6 = (uint64_t*) 0;
uint64_t* NID_MACHINE_WORD_7 = (uint64_t*) 0;
uint64_t* NID_MACHINE_WORD_8 = (uint64_t*) 0;

uint64_t* NID_MACHINE_WORD_MINUS_1 = (uint64_t*) 0;

uint64_t* NID_MACHINE_WORD_SIZE      = (uint64_t*) 0;
uint64_t* NID_MACHINE_WORD_SIZE_MASK = (uint64_t*) 0;

uint64_t* NID_MACHINE_WORD_SIZE_MINUS_HALF_WORD_SIZE   = (uint64_t*) 0;
uint64_t* NID_MACHINE_WORD_SIZE_MINUS_SINGLE_WORD_SIZE = (uint64_t*) 0;

uint64_t* NID_HALF_WORD_SIZE   = (uint64_t*) 0;
uint64_t* NID_SINGLE_WORD_SIZE = (uint64_t*) 0;
uint64_t* NID_DOUBLE_WORD_SIZE = (uint64_t*) 0;

uint64_t* NID_BYTE_MASK        = (uint64_t*) 0;
uint64_t* NID_HALF_WORD_MASK   = (uint64_t*) 0;
uint64_t* NID_SINGLE_WORD_MASK = (uint64_t*) 0;

uint64_t* NID_LSB_MASK = (uint64_t*) 0;

uint64_t* NID_BYTE_SIZE_IN_BASE_BITS = (uint64_t*) 0;

uint64_t* SID_INSTRUCTION_WORD           = (uint64_t*) 0;
uint64_t* NID_INSTRUCTION_WORD_SIZE_MASK = (uint64_t*) 0;

uint64_t* NID_MAX_STRING_LENGTH = (uint64_t*) 0;

uint64_t* SID_DOUBLE_MACHINE_WORD = (uint64_t*) 0;

// ------------------------- INITIALIZATION ------------------------

void init_interface_sorts() {
  SID_BOOLEAN = new_bitvec(1, "Boolean");

  NID_FALSE = new_constant(OP_CONSTD, SID_BOOLEAN, 0, 0, "false");
  NID_TRUE  = new_constant(OP_CONSTD, SID_BOOLEAN, 1, 0, "true");

  SID_BYTE = new_bitvec(8, "8-bit byte");

  NID_BYTE_0 = new_constant(OP_CONSTD, SID_BYTE, 0, 0, "byte 0");

  SID_HALF_WORD = new_bitvec(16, "16-bit half word");

  SID_SINGLE_WORD = new_bitvec(32, "32-bit single word");

  NID_SINGLE_WORD_0 = new_constant(OP_CONSTD, SID_SINGLE_WORD, 0, 0, "single-word 0");
  NID_SINGLE_WORD_1 = new_constant(OP_CONSTD, SID_SINGLE_WORD, 1, 0, "single-word 1");
  NID_SINGLE_WORD_2 = new_constant(OP_CONSTD, SID_SINGLE_WORD, 2, 0, "single-word 2");
  NID_SINGLE_WORD_3 = new_constant(OP_CONSTD, SID_SINGLE_WORD, 3, 0, "single-word 3");
  NID_SINGLE_WORD_4 = new_constant(OP_CONSTD, SID_SINGLE_WORD, 4, 0, "single-word 4");
  NID_SINGLE_WORD_5 = new_constant(OP_CONSTD, SID_SINGLE_WORD, 5, 0, "single-word 5");
  NID_SINGLE_WORD_6 = new_constant(OP_CONSTD, SID_SINGLE_WORD, 6, 0, "single-word 6");
  NID_SINGLE_WORD_7 = new_constant(OP_CONSTD, SID_SINGLE_WORD, 7, 0, "single-word 7");
  NID_SINGLE_WORD_8 = new_constant(OP_CONSTD, SID_SINGLE_WORD, 8, 0, "single-word 8");

  NID_SINGLE_WORD_MINUS_1 = new_constant(OP_CONSTD, SID_SINGLE_WORD, -1, 0, "single-word -1");

  if (IS64BITTARGET) {
    SID_DOUBLE_WORD = new_bitvec(64, "64-bit double word");

    NID_DOUBLE_WORD_0 = new_constant(OP_CONSTD, SID_DOUBLE_WORD, 0, 0, "double-word 0");
    NID_DOUBLE_WORD_1 = new_constant(OP_CONSTD, SID_DOUBLE_WORD, 1, 0, "double-word 1");
    NID_DOUBLE_WORD_2 = new_constant(OP_CONSTD, SID_DOUBLE_WORD, 2, 0, "double-word 2");
    NID_DOUBLE_WORD_3 = new_constant(OP_CONSTD, SID_DOUBLE_WORD, 3, 0, "double-word 3");
    NID_DOUBLE_WORD_4 = new_constant(OP_CONSTD, SID_DOUBLE_WORD, 4, 0, "double-word 4");
    NID_DOUBLE_WORD_5 = new_constant(OP_CONSTD, SID_DOUBLE_WORD, 5, 0, "double-word 5");
    NID_DOUBLE_WORD_6 = new_constant(OP_CONSTD, SID_DOUBLE_WORD, 6, 0, "double-word 6");
    NID_DOUBLE_WORD_7 = new_constant(OP_CONSTD, SID_DOUBLE_WORD, 7, 0, "double-word 7");
    NID_DOUBLE_WORD_8 = new_constant(OP_CONSTD, SID_DOUBLE_WORD, 8, 0, "double-word 8");

    NID_DOUBLE_WORD_MINUS_1 = new_constant(OP_CONSTD, SID_DOUBLE_WORD, -1, 0, "double-word -1");

    SID_MACHINE_WORD = SID_DOUBLE_WORD;

    NID_MACHINE_WORD_0 = NID_DOUBLE_WORD_0;
    NID_MACHINE_WORD_1 = NID_DOUBLE_WORD_1;
    NID_MACHINE_WORD_2 = NID_DOUBLE_WORD_2;
    NID_MACHINE_WORD_3 = NID_DOUBLE_WORD_3;
    NID_MACHINE_WORD_4 = NID_DOUBLE_WORD_4;
    NID_MACHINE_WORD_5 = NID_DOUBLE_WORD_5;
    NID_MACHINE_WORD_6 = NID_DOUBLE_WORD_6;
    NID_MACHINE_WORD_7 = NID_DOUBLE_WORD_7;
    NID_MACHINE_WORD_8 = NID_DOUBLE_WORD_8;

    NID_MACHINE_WORD_MINUS_1 = NID_DOUBLE_WORD_MINUS_1;

    NID_MACHINE_WORD_SIZE      = NID_MACHINE_WORD_8;
    NID_MACHINE_WORD_SIZE_MASK = NID_MACHINE_WORD_7;

    NID_MACHINE_WORD_SIZE_MINUS_HALF_WORD_SIZE   = NID_MACHINE_WORD_6;
    NID_MACHINE_WORD_SIZE_MINUS_SINGLE_WORD_SIZE = NID_MACHINE_WORD_4;
  } else {
    // assert: 32-bit system
    SID_MACHINE_WORD = SID_SINGLE_WORD;

    NID_MACHINE_WORD_0 = NID_SINGLE_WORD_0;
    NID_MACHINE_WORD_1 = NID_SINGLE_WORD_1;
    NID_MACHINE_WORD_2 = NID_SINGLE_WORD_2;
    NID_MACHINE_WORD_3 = NID_SINGLE_WORD_3;
    NID_MACHINE_WORD_4 = NID_SINGLE_WORD_4;
    NID_MACHINE_WORD_5 = NID_SINGLE_WORD_5;
    NID_MACHINE_WORD_6 = NID_SINGLE_WORD_6;
    NID_MACHINE_WORD_7 = NID_SINGLE_WORD_7;
    NID_MACHINE_WORD_8 = NID_SINGLE_WORD_8;

    NID_MACHINE_WORD_MINUS_1 = NID_SINGLE_WORD_MINUS_1;

    NID_MACHINE_WORD_SIZE      = NID_MACHINE_WORD_4;
    NID_MACHINE_WORD_SIZE_MASK = NID_MACHINE_WORD_3;

    NID_MACHINE_WORD_SIZE_MINUS_HALF_WORD_SIZE   = NID_MACHINE_WORD_2;
    NID_MACHINE_WORD_SIZE_MINUS_SINGLE_WORD_SIZE = NID_MACHINE_WORD_0;
  }

  NID_HALF_WORD_SIZE   = NID_MACHINE_WORD_2;
  NID_SINGLE_WORD_SIZE = NID_MACHINE_WORD_4;
  NID_DOUBLE_WORD_SIZE = NID_MACHINE_WORD_8;

  NID_BYTE_MASK        = new_constant(OP_CONSTH, SID_MACHINE_WORD, 255, 2, "maximum least-significant byte value");
  NID_HALF_WORD_MASK   = new_constant(OP_CONSTH, SID_MACHINE_WORD, 65535, 4, "maximum least-significant half-word value");
  NID_SINGLE_WORD_MASK = new_constant(OP_CONSTH, SID_MACHINE_WORD, 4294967295, 8, "maximum least-significant single-word value");

  NID_LSB_MASK = new_constant(OP_CONSTD, SID_MACHINE_WORD, -2, 0, "all bits but LSB set");

  NID_BYTE_SIZE_IN_BASE_BITS = NID_MACHINE_WORD_3;

  SID_INSTRUCTION_WORD = SID_SINGLE_WORD;

  NID_INSTRUCTION_WORD_SIZE_MASK = NID_MACHINE_WORD_3;

  NID_MAX_STRING_LENGTH = new_constant(OP_CONSTD, SID_MACHINE_WORD, MAX_STRING_LENGTH, 0, "maximum string length");

  SID_DOUBLE_MACHINE_WORD = new_bitvec(2 * WORDSIZEINBITS, "double machine word");
}

// -----------------------------------------------------------------
// ---------------------------- MEMORY -----------------------------
// -----------------------------------------------------------------

// ------------------------ GLOBAL CONSTANTS -----------------------

uint64_t ISBYTEMEMORY = 0;

uint64_t* SID_MEMORY_WORD = (uint64_t*) 0;

// ------------------------- INITIALIZATION ------------------------

void init_interface_memory() {
  if (ISBYTEMEMORY)
    SID_MEMORY_WORD = SID_BYTE;
  else
    SID_MEMORY_WORD = SID_MACHINE_WORD;
}

// -----------------------------------------------------------------
// ---------------------------- KERNEL -----------------------------
// -----------------------------------------------------------------

void print_interface_kernel();

void new_kernel_state(uint64_t bytes_to_read);

// ------------------------ GLOBAL CONSTANTS -----------------------

uint64_t* NID_EXIT_SYSCALL_ID   = (uint64_t*) 0;
uint64_t* NID_BRK_SYSCALL_ID    = (uint64_t*) 0;
uint64_t* NID_OPENAT_SYSCALL_ID = (uint64_t*) 0;
uint64_t* NID_READ_SYSCALL_ID   = (uint64_t*) 0;
uint64_t* NID_WRITE_SYSCALL_ID  = (uint64_t*) 0;

// ------------------------ GLOBAL VARIABLES -----------------------

uint64_t* state_program_break_nid = (uint64_t*) 0;
uint64_t* init_program_break_nid  = (uint64_t*) 0;
uint64_t* next_program_break_nid  = (uint64_t*) 0;

uint64_t* state_file_descriptor_nid = (uint64_t*) 0;
uint64_t* init_file_descriptor_nid  = (uint64_t*) 0;
uint64_t* next_file_descriptor_nid  = (uint64_t*) 0;

uint64_t* readable_bytes_nid = (uint64_t*) 0;

uint64_t* state_readable_bytes_nid = (uint64_t*) 0;
uint64_t* init_readable_bytes_nid  = (uint64_t*) 0;
uint64_t* next_readable_bytes_nid  = (uint64_t*) 0;

uint64_t* state_read_bytes_nid = (uint64_t*) 0;
uint64_t* init_read_bytes_nid  = (uint64_t*) 0;
uint64_t* next_read_bytes_nid  = (uint64_t*) 0;

// ------------------------- INITIALIZATION ------------------------

void init_interface_kernel() {
  NID_EXIT_SYSCALL_ID = new_constant(OP_CONSTD, SID_MACHINE_WORD,
    SYSCALL_EXIT, 0,
    format_comment_binary("exit syscall ID", SYSCALL_EXIT));
  NID_BRK_SYSCALL_ID = new_constant(OP_CONSTD, SID_MACHINE_WORD,
    SYSCALL_BRK, 0,
    format_comment_binary("brk syscall ID", SYSCALL_BRK));
  NID_OPENAT_SYSCALL_ID = new_constant(OP_CONSTD, SID_MACHINE_WORD,
    SYSCALL_OPENAT, 0,
    format_comment_binary("openat syscall ID", SYSCALL_OPENAT));
  NID_READ_SYSCALL_ID = new_constant(OP_CONSTD, SID_MACHINE_WORD,
    SYSCALL_READ, 0,
    format_comment_binary("read syscall ID", SYSCALL_READ));
  NID_WRITE_SYSCALL_ID = new_constant(OP_CONSTD, SID_MACHINE_WORD,
    SYSCALL_WRITE, 0,
    format_comment_binary("write syscall ID", SYSCALL_WRITE));
}

// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~
// -----------------------------------------------------------------
// -----------------    A R C H I T E C T U R E    -----------------
// -----------------------------------------------------------------
// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~

// -----------------------------------------------------------------
// --------------------------- REGISTERS ---------------------------
// -----------------------------------------------------------------

void print_register_sorts();

uint64_t* load_register_value(uint64_t* reg_nid, char* comment);
uint64_t* store_register_value(uint64_t* reg_nid, uint64_t* value_nid, uint64_t* register_file_nid, char* comment);

void new_register_file_state();
void print_register_file_state();

// ------------------------ GLOBAL CONSTANTS -----------------------

uint64_t* SID_REGISTER_ADDRESS = (uint64_t*) 0;

uint64_t* NID_ZR  = (uint64_t*) 0;
uint64_t* NID_RA  = (uint64_t*) 0;
uint64_t* NID_SP  = (uint64_t*) 0;
uint64_t* NID_GP  = (uint64_t*) 0;
uint64_t* NID_TP  = (uint64_t*) 0;
uint64_t* NID_T0  = (uint64_t*) 0;
uint64_t* NID_T1  = (uint64_t*) 0;
uint64_t* NID_T2  = (uint64_t*) 0;
uint64_t* NID_S0  = (uint64_t*) 0;
uint64_t* NID_S1  = (uint64_t*) 0;
uint64_t* NID_A0  = (uint64_t*) 0;
uint64_t* NID_A1  = (uint64_t*) 0;
uint64_t* NID_A2  = (uint64_t*) 0;
uint64_t* NID_A3  = (uint64_t*) 0;
uint64_t* NID_A4  = (uint64_t*) 0;
uint64_t* NID_A5  = (uint64_t*) 0;
uint64_t* NID_A6  = (uint64_t*) 0;
uint64_t* NID_A7  = (uint64_t*) 0;
uint64_t* NID_S2  = (uint64_t*) 0;
uint64_t* NID_S3  = (uint64_t*) 0;
uint64_t* NID_S4  = (uint64_t*) 0;
uint64_t* NID_S5  = (uint64_t*) 0;
uint64_t* NID_S6  = (uint64_t*) 0;
uint64_t* NID_S7  = (uint64_t*) 0;
uint64_t* NID_S8  = (uint64_t*) 0;
uint64_t* NID_S9  = (uint64_t*) 0;
uint64_t* NID_S10 = (uint64_t*) 0;
uint64_t* NID_S11 = (uint64_t*) 0;
uint64_t* NID_T3  = (uint64_t*) 0;
uint64_t* NID_T4  = (uint64_t*) 0;
uint64_t* NID_T5  = (uint64_t*) 0;
uint64_t* NID_T6  = (uint64_t*) 0;

uint64_t* SID_REGISTER_STATE = (uint64_t*) 0;

// ------------------------ GLOBAL VARIABLES -----------------------

uint64_t* zeroed_register_file_nid  = (uint64_t*) 0;
uint64_t* initial_register_file_nid = (uint64_t*) 0;

uint64_t* state_register_file_nid = (uint64_t*) 0;
uint64_t* init_register_file_nid  = (uint64_t*) 0;
uint64_t* next_register_file_nid  = (uint64_t*) 0;

// ------------------------- INITIALIZATION ------------------------

void init_register_file_sorts() {
  SID_REGISTER_ADDRESS = new_bitvec(5, "5-bit register address");

  NID_ZR  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_ZR, 5, (char*) *(REGISTERS + REG_ZR));
  NID_RA  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_RA, 5, (char*) *(REGISTERS + REG_RA));
  NID_SP  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_SP, 5, (char*) *(REGISTERS + REG_SP));
  NID_GP  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_GP, 5, (char*) *(REGISTERS + REG_GP));
  NID_TP  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_TP, 5, (char*) *(REGISTERS + REG_TP));
  NID_T0  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_T0, 5, (char*) *(REGISTERS + REG_T0));
  NID_T1  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_T1, 5, (char*) *(REGISTERS + REG_T1));
  NID_T2  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_T2, 5, (char*) *(REGISTERS + REG_T2));
  NID_S0  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_S0, 5, (char*) *(REGISTERS + REG_S0));
  NID_S1  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_S1, 5, (char*) *(REGISTERS + REG_S1));
  NID_A0  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_A0, 5, (char*) *(REGISTERS + REG_A0));
  NID_A1  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_A1, 5, (char*) *(REGISTERS + REG_A1));
  NID_A2  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_A2, 5, (char*) *(REGISTERS + REG_A2));
  NID_A3  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_A3, 5, (char*) *(REGISTERS + REG_A3));
  NID_A4  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_A4, 5, (char*) *(REGISTERS + REG_A4));
  NID_A5  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_A5, 5, (char*) *(REGISTERS + REG_A5));
  NID_A6  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_A6, 5, (char*) *(REGISTERS + REG_A6));
  NID_A7  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_A7, 5, (char*) *(REGISTERS + REG_A7));
  NID_S2  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_S2, 5, (char*) *(REGISTERS + REG_S2));
  NID_S3  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_S3, 5, (char*) *(REGISTERS + REG_S3));
  NID_S4  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_S4, 5, (char*) *(REGISTERS + REG_S4));
  NID_S5  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_S5, 5, (char*) *(REGISTERS + REG_S5));
  NID_S6  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_S6, 5, (char*) *(REGISTERS + REG_S6));
  NID_S7  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_S7, 5, (char*) *(REGISTERS + REG_S7));
  NID_S8  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_S8, 5, (char*) *(REGISTERS + REG_S8));
  NID_S9  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_S9, 5, (char*) *(REGISTERS + REG_S9));
  NID_S10 = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_S10, 5, (char*) *(REGISTERS + REG_S10));
  NID_S11 = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_S11, 5, (char*) *(REGISTERS + REG_S11));
  NID_T3  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_T3, 5, (char*) *(REGISTERS + REG_T3));
  NID_T4  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_T4, 5, (char*) *(REGISTERS + REG_T4));
  NID_T5  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_T5, 5, (char*) *(REGISTERS + REG_T5));
  NID_T6  = new_constant(OP_CONST, SID_REGISTER_ADDRESS, REG_T6, 5, (char*) *(REGISTERS + REG_T6));

  SID_REGISTER_STATE = new_array(SID_REGISTER_ADDRESS, SID_MACHINE_WORD, "register state");
}

// -----------------------------------------------------------------
// ---------------------------- MEMORY -----------------------------
// -----------------------------------------------------------------

void print_memory_sorts();

void new_segmentation();
void print_segmentation();

void new_code_segment();
void print_code_segment();

void new_memory_state();
void print_memory_state();

uint64_t* is_address_in_segment(uint64_t* vaddr_nid, uint64_t* start_nid, uint64_t* end_nid);
uint64_t* is_address_in_code_segment(uint64_t* vaddr_nid);
uint64_t* is_address_in_data_segment(uint64_t* vaddr_nid);
uint64_t* is_address_in_heap_segment(uint64_t* vaddr_nid);
uint64_t* is_address_in_stack_segment(uint64_t* vaddr_nid);
uint64_t* is_address_in_main_memory(uint64_t* vaddr_nid);

uint64_t* is_range_in_segment(uint64_t* vaddr_nid, uint64_t* range_nid, uint64_t* start_nid, uint64_t* end_nid);
uint64_t* is_range_in_code_segment(uint64_t* vaddr_nid, uint64_t* range_nid);
uint64_t* is_range_in_data_segment(uint64_t* vaddr_nid, uint64_t* range_nid);
uint64_t* is_range_in_heap_segment(uint64_t* vaddr_nid, uint64_t* range_nid);
uint64_t* is_range_in_stack_segment(uint64_t* vaddr_nid, uint64_t* range_nid);
uint64_t* is_range_in_main_memory(uint64_t* vaddr_nid, uint64_t* range_nid);

uint64_t* vaddr_to_code_segment_laddr(uint64_t* vaddr_nid);

uint64_t* vaddr_to_32_bit_laddr(uint64_t* vaddr_nid);
uint64_t* vaddr_to_29_bit_laddr(uint64_t* vaddr_nid);
uint64_t* vaddr_to_30_bit_laddr(uint64_t* vaddr_nid);

uint64_t* vaddr_to_laddr(uint64_t* vaddr_nid);

uint64_t* load_byte_from_bytes(uint64_t* vaddr_nid, uint64_t* memory_nid);
uint64_t* store_byte_in_bytes(uint64_t* vaddr_nid, uint64_t* byte_nid, uint64_t* memory_nid);

uint64_t* get_vaddr_alignment(uint64_t* vaddr_nid, uint64_t* alignment_nid);
uint64_t* shift_by_alignment_in_bits(uint64_t* vaddr_nid, uint64_t* alignment_nid);
uint64_t* shift_from_vaddr(uint64_t* vaddr_nid, uint64_t* alignment_nid, uint64_t* value_nid);
uint64_t* shift_to_vaddr(uint64_t* vaddr_nid, uint64_t* alignment_nid, uint64_t* value_nid);
uint64_t* slice_byte_from_machine_word(uint64_t* word_nid);
uint64_t* extend_byte_to_machine_word(char* op, uint64_t* byte_nid);
uint64_t* insert_value_into_machine_word(uint64_t* word_nid, uint64_t* vaddr_nid, uint64_t* value_mask_nid, uint64_t* value_nid);

uint64_t* load_byte_from_machine_word(uint64_t* vaddr_nid, uint64_t* memory_nid);
uint64_t* store_byte_in_machine_word(uint64_t* vaddr_nid, uint64_t* byte_nid, uint64_t* memory_nid);

uint64_t* load_byte(uint64_t* vaddr_nid, uint64_t* memory_nid);
uint64_t* store_byte(uint64_t* vaddr_nid, uint64_t* byte_nid, uint64_t* memory_nid);

uint64_t* slice_lower_byte_from_half_word(uint64_t* word_nid);
uint64_t* slice_upper_byte_from_half_word(uint64_t* word_nid);

uint64_t* load_half_word_from_bytes(uint64_t* vaddr_nid, uint64_t* memory_nid);
uint64_t* store_half_word_in_bytes(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid);

uint64_t* is_contained_in_machine_word(uint64_t* vaddr_nid, uint64_t* relative_size_nid);
uint64_t* slice_half_word_from_machine_word(uint64_t* word_nid);
uint64_t* extend_half_word_to_machine_word(char* op, uint64_t* word_nid);

uint64_t* load_half_word_from_machine_words(uint64_t* vaddr_nid, uint64_t* memory_nid);
uint64_t* store_half_word_in_machine_words(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid);

uint64_t* load_half_word(uint64_t* vaddr_nid, uint64_t* memory_nid);
uint64_t* store_half_word(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid);

uint64_t* load_single_word_from_half_words(uint64_t* vaddr_nid, uint64_t* memory_nid);
uint64_t* store_single_word_in_half_words(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid);

uint64_t* slice_single_word_from_machine_word(uint64_t* word_nid);
uint64_t* extend_single_word_to_machine_word(char* op, uint64_t* word_nid);

uint64_t* load_single_word_from_machine_words(uint64_t* vaddr_nid, uint64_t* memory_nid);
uint64_t* store_single_word_in_machine_words(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid);

uint64_t* load_single_word(uint64_t* vaddr_nid, uint64_t* memory_nid);
uint64_t* store_single_word(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid);

uint64_t* slice_lower_single_word_from_double_word(uint64_t* word_nid);
uint64_t* slice_upper_single_word_from_double_word(uint64_t* word_nid);

uint64_t* load_double_word_from_single_words(uint64_t* vaddr_nid, uint64_t* memory_nid);
uint64_t* store_double_word_in_single_words(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid);

uint64_t* load_double_word_from_machine_words(uint64_t* vaddr_nid, uint64_t* memory_nid);
uint64_t* store_double_word_in_machine_words(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid);

uint64_t* load_double_word(uint64_t* vaddr_nid, uint64_t* memory_nid);
uint64_t* store_double_word(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid);

uint64_t* load_machine_word_from_word_memory(uint64_t* vaddr_nid, uint64_t* memory_nid);
uint64_t* store_machine_word_in_word_memory(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid);

uint64_t* load_machine_word(uint64_t* vaddr_nid, uint64_t* memory_nid);
uint64_t* store_machine_word(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid);

uint64_t* fetch_instruction(uint64_t* pc_nid);

// ------------------------ GLOBAL CONSTANTS -----------------------

uint64_t CODE_ADDRESS_SPACE = 0; // number of bits in code segment addresses

uint64_t* SID_CODE_ADDRESS = (uint64_t*) 0;
uint64_t* SID_CODE_STATE   = (uint64_t*) 0;

uint64_t* NID_CODE_START = (uint64_t*) 0;
uint64_t* NID_CODE_END   = (uint64_t*) 0;

uint64_t MEMORY_ADDRESS_SPACE = 0; // number of bits in main memory addresses

uint64_t* SID_MEMORY_ADDRESS = (uint64_t*) 0;
uint64_t* SID_MEMORY_STATE   = (uint64_t*) 0;

uint64_t* NID_DATA_START = (uint64_t*) 0;
uint64_t* NID_DATA_END   = (uint64_t*) 0;

uint64_t* NID_HEAP_START = (uint64_t*) 0;
uint64_t* NID_HEAP_END   = (uint64_t*) 0;

uint64_t* NID_STACK_START = (uint64_t*) 0;
uint64_t* NID_STACK_END   = (uint64_t*) 0;

// ------------------------ GLOBAL VARIABLES -----------------------

uint64_t heap_start     = 0;
uint64_t heap_size      = 0;
uint64_t heap_allowance = 0;

uint64_t stack_start     = 0;
uint64_t stack_size      = 0;
uint64_t stack_allowance = 0;

uint64_t* zeroed_code_segment_nid  = (uint64_t*) 0;
uint64_t* initial_code_segment_nid = (uint64_t*) 0;

uint64_t* state_code_segment_nid = (uint64_t*) 0;
uint64_t* init_code_segment_nid  = (uint64_t*) 0;
uint64_t* next_code_segment_nid  = (uint64_t*) 0;

uint64_t* zeroed_main_memory_nid   = (uint64_t*) 0;
uint64_t* initial_main_memory_nid  = (uint64_t*) 0;
uint64_t* initial_data_segment_nid = (uint64_t*) 0;
uint64_t* initial_heap_segment_nid = (uint64_t*) 0;

uint64_t* state_main_memory_nid = (uint64_t*) 0;
uint64_t* init_main_memory_nid  = (uint64_t*) 0;
uint64_t* next_main_memory_nid  = (uint64_t*) 0;

// ------------------------- INITIALIZATION ------------------------

void init_memory_sorts() {
  CODE_ADDRESS_SPACE = log_two(code_size / INSTRUCTIONSIZE);

  if (code_size / INSTRUCTIONSIZE > two_to_the_power_of(CODE_ADDRESS_SPACE))
    CODE_ADDRESS_SPACE = CODE_ADDRESS_SPACE + 1;

  SID_CODE_ADDRESS = new_bitvec(CODE_ADDRESS_SPACE,
    format_comment("%lu-bit code segment address over 32-bit single words", CODE_ADDRESS_SPACE));

  SID_CODE_STATE = new_array(SID_CODE_ADDRESS, SID_INSTRUCTION_WORD, "code segment state");

  if (ISBYTEMEMORY) {
    MEMORY_ADDRESS_SPACE = 32;

    SID_MEMORY_ADDRESS = new_bitvec(MEMORY_ADDRESS_SPACE, "32-bit memory address over 8-bit bytes");
  } else if (IS64BITTARGET) {
    MEMORY_ADDRESS_SPACE = 29;

    SID_MEMORY_ADDRESS = new_bitvec(MEMORY_ADDRESS_SPACE, "29-bit memory address over 64-bit double words");
  } else {
    // assert: 32-bit system
    MEMORY_ADDRESS_SPACE = 30;

    SID_MEMORY_ADDRESS = new_bitvec(MEMORY_ADDRESS_SPACE, "30-bit memory address over 32-bit single words");
  }

  SID_MEMORY_STATE = new_array(SID_MEMORY_ADDRESS, SID_MEMORY_WORD, "main memory state");
}

// -----------------------------------------------------------------
// ------------------------- INSTRUCTIONS --------------------------
// -----------------------------------------------------------------

uint64_t* get_instruction_opcode(uint64_t* ir_nid);
uint64_t* get_instruction_funct3(uint64_t* ir_nid);
uint64_t* get_instruction_funct7(uint64_t* ir_nid);
uint64_t* get_instruction_funct6(uint64_t* ir_nid);
uint64_t* get_instruction_rd(uint64_t* ir_nid);
uint64_t* get_instruction_rs1(uint64_t* ir_nid);
uint64_t* get_instruction_rs2(uint64_t* ir_nid);

uint64_t* sign_extend_IS_immediate(uint64_t* imm_nid);
uint64_t* get_instruction_I_immediate(uint64_t* ir_nid);
uint64_t* get_instruction_I_immediate_32(uint64_t* ir_nid);
uint64_t* get_instruction_shamt(uint64_t* ir_nid);
uint64_t* get_instruction_shamt_32(uint64_t* ir_nid);
uint64_t* get_instruction_S_immediate(uint64_t* ir_nid);
uint64_t* sign_extend_SB_immediate(uint64_t* imm_nid);
uint64_t* get_instruction_SB_immediate(uint64_t* ir_nid);
uint64_t* sign_extend_U_immediate(uint64_t* imm_nid);
uint64_t* get_instruction_U_immediate(uint64_t* ir_nid);
uint64_t* sign_extend_UJ_immediate(uint64_t* imm_nid);
uint64_t* get_instruction_UJ_immediate(uint64_t* ir_nid);

uint64_t* decode_opcode(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* opcode_nid, char* opcode_comment,
  uint64_t* execute_nid, char* execute_comment,
  uint64_t* other_opcode_nid);
uint64_t* decode_funct3(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* funct3_nid, char* funct3_comment,
  uint64_t* execute_nid, char* execute_comment,
  uint64_t* other_funct3_nid);
uint64_t* decode_funct3_conditional(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* funct3_nid, char* funct3_comment,
  uint64_t* evaluate_nid, uint64_t* execute_nid, char* execute_comment,
  uint64_t* other_funct3_nid);
uint64_t* decode_funct7(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* funct7_nid, char* funct7_comment,
  uint64_t* execute_nid, char* execute_comment,
  uint64_t* other_funct7_nid);

uint64_t* decode_lui(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* lui_nid, char* comment,
  uint64_t* other_opcode_nid);
uint64_t* decode_auipc(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* auipc_nid, char* comment,
  uint64_t* other_opcode_nid);
uint64_t* decode_funct7_6(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* funct_nid, char* funct_comment,
  uint64_t* execute_nid, char* execute_comment,
  uint64_t* other_funct_nid);
uint64_t* decode_shift_w(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* funct7_sll_srl_nid, uint64_t* slliw_nid, uint64_t* srliw_nid,
  uint64_t* funct7_sra_nid, uint64_t* sraiw_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* no_funct7_nid);
uint64_t* decode_shift_imm(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* funct_sll_srl_nid, uint64_t* slli_nid, uint64_t* srli_nid,
  uint64_t* funct_sra_nid, uint64_t* srai_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* no_funct7_nid);
uint64_t* decode_illegal_shift_imm(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* slli_nid, uint64_t* srli_nid, uint64_t* srai_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* no_funct7_nid, uint64_t* other_opcode_nid);
uint64_t* decode_imm_32(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* addiw_nid, uint64_t* slliw_nid, uint64_t* srliw_nid, uint64_t* sraiw_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* no_funct7_nid, uint64_t* other_opcode_nid);
uint64_t* decode_imm(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* addi_nid, uint64_t* slti_nid, uint64_t* sltiu_nid,
  uint64_t* xori_nid, uint64_t* ori_nid, uint64_t* andi_nid,
  uint64_t* slli_nid, uint64_t* srli_nid, uint64_t* srai_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* no_funct7_nid, uint64_t* other_opcode_nid);
uint64_t* decode_op(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* add_nid, uint64_t* sub_nid,
  uint64_t* slt_nid, uint64_t* sltu_nid,
  uint64_t* xor_nid, uint64_t* or_nid, uint64_t* and_nid,
  uint64_t* sll_nid, uint64_t* srl_nid, uint64_t* sra_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* RV32M_nid, uint64_t* other_opcode_nid);
uint64_t* decode_RV32M(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* mul_nid, uint64_t* mulh_nid, uint64_t* mulhsu_nid, uint64_t* mulhu_nid,
  uint64_t* div_nid, uint64_t* divu_nid, uint64_t* rem_nid, uint64_t* remu_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* no_funct7_nid);
uint64_t* decode_load(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* ld_nid,
  uint64_t* lw_nid, uint64_t* lwu_nid,
  uint64_t* lh_nid, uint64_t* lhu_nid,
  uint64_t* lb_nid, uint64_t* lbu_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* other_opcode_nid);
uint64_t* decode_store(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* sd_nid, uint64_t* sw_nid,
  uint64_t* sh_nid, uint64_t* sb_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* other_opcode_nid);
uint64_t* decode_branch(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* beq_nid, uint64_t* bne_nid,
  uint64_t* blt_nid, uint64_t* bge_nid,
  uint64_t* bltu_nid, uint64_t* bgeu_nid,
  uint64_t* branch_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* other_opcode_nid);
uint64_t* decode_jal(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* jal_nid, char* comment,
  uint64_t* other_opcode_nid);
uint64_t* decode_jalr(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* jalr_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* other_opcode_nid);

uint64_t* decode_instruction(uint64_t* ir_nid);

uint64_t* get_rs1_value_plus_I_immediate(uint64_t* ir_nid);
uint64_t* imm_data_flow(uint64_t* ir_nid, uint64_t* other_data_flow_nid);

uint64_t* op_data_flow(uint64_t* ir_nid, uint64_t* other_data_flow_nid);

uint64_t* load_data_flow(uint64_t* ir_nid, uint64_t* memory_nid, uint64_t* other_data_flow_nid);
uint64_t* load_no_seg_faults(uint64_t* ir_nid);

uint64_t* get_pc_value_plus_4(uint64_t* pc_nid);
uint64_t* jal_data_flow(uint64_t* pc_nid, uint64_t* ir_nid, uint64_t* other_data_flow_nid);
uint64_t* jalr_data_flow(uint64_t* pc_nid, uint64_t* ir_nid, uint64_t* other_data_flow_nid);

uint64_t* lui_data_flow(uint64_t* ir_nid, uint64_t* other_data_flow_nid);
uint64_t* get_pc_value_plus_U_immediate(uint64_t* pc_nid, uint64_t* ir_nid);
uint64_t* auipc_data_flow(uint64_t* pc_nid, uint64_t* ir_nid, uint64_t* other_data_flow_nid);

uint64_t* core_register_data_flow(uint64_t* pc_nid, uint64_t* ir_nid,
  uint64_t* register_file_nid, uint64_t* memory_nid);

uint64_t* get_rs1_value_plus_S_immediate(uint64_t* ir_nid);
uint64_t* store_data_flow(uint64_t* ir_nid, uint64_t* memory_nid, uint64_t* other_data_flow_nid);
uint64_t* store_no_seg_faults(uint64_t* ir_nid);

uint64_t* core_memory_data_flow(uint64_t* ir_nid, uint64_t* memory_nid);

uint64_t* get_pc_value_plus_SB_immediate(uint64_t* pc_nid, uint64_t* ir_nid);
uint64_t* branch_control_flow(uint64_t* pc_nid, uint64_t* ir_nid, uint64_t* other_control_flow_nid);

uint64_t* get_pc_value_plus_UJ_immediate(uint64_t* pc_nid, uint64_t* ir_nid);
uint64_t* jal_control_flow(uint64_t* pc_nid, uint64_t* ir_nid, uint64_t* other_control_flow_nid);

uint64_t* jalr_control_flow(uint64_t* pc_nid, uint64_t* ir_nid, uint64_t* other_control_flow_nid);

uint64_t* core_control_flow(uint64_t* pc_nid, uint64_t* ir_nid);

// ------------------------ GLOBAL CONSTANTS -----------------------

// RISC-U codes

uint64_t* SID_OPCODE = (uint64_t*) 0;

uint64_t* NID_OP_LOAD   = (uint64_t*) 0;
uint64_t* NID_OP_IMM    = (uint64_t*) 0;
uint64_t* NID_OP_STORE  = (uint64_t*) 0;
uint64_t* NID_OP_OP     = (uint64_t*) 0;
uint64_t* NID_OP_LUI    = (uint64_t*) 0;
uint64_t* NID_OP_BRANCH = (uint64_t*) 0;
uint64_t* NID_OP_JALR   = (uint64_t*) 0;
uint64_t* NID_OP_JAL    = (uint64_t*) 0;
uint64_t* NID_OP_SYSTEM = (uint64_t*) 0;

uint64_t* SID_FUNCT3 = (uint64_t*) 0;

uint64_t* NID_F3_NOP         = (uint64_t*) 0;
uint64_t* NID_F3_ADDI        = (uint64_t*) 0;
uint64_t* NID_F3_ADD_SUB_MUL = (uint64_t*) 0;
uint64_t* NID_F3_DIVU        = (uint64_t*) 0;
uint64_t* NID_F3_REMU        = (uint64_t*) 0;
uint64_t* NID_F3_SLTU        = (uint64_t*) 0;
uint64_t* NID_F3_LD          = (uint64_t*) 0;
uint64_t* NID_F3_SD          = (uint64_t*) 0;
uint64_t* NID_F3_LW          = (uint64_t*) 0;
uint64_t* NID_F3_SW          = (uint64_t*) 0;
uint64_t* NID_F3_BEQ         = (uint64_t*) 0;
uint64_t* NID_F3_JALR        = (uint64_t*) 0;
uint64_t* NID_F3_ECALL       = (uint64_t*) 0;

uint64_t* SID_FUNCT7 = (uint64_t*) 0;

uint64_t* NID_F7_ADD  = (uint64_t*) 0;
uint64_t* NID_F7_MUL  = (uint64_t*) 0;
uint64_t* NID_F7_SUB  = (uint64_t*) 0;
uint64_t* NID_F7_DIVU = (uint64_t*) 0;
uint64_t* NID_F7_REMU = (uint64_t*) 0;
uint64_t* NID_F7_SLTU = (uint64_t*) 0;

uint64_t* NID_F7_MUL_DIV_REM = (uint64_t*) 0;

uint64_t* SID_FUNCT12 = (uint64_t*) 0;

uint64_t* NID_F12_ECALL = (uint64_t*) 0;

uint64_t* NID_ECALL_I = (uint64_t*) 0;

// immediate sorts

uint64_t* SID_1_BIT_IMM  = (uint64_t*) 0;
uint64_t* SID_4_BIT_IMM  = (uint64_t*) 0;
uint64_t* SID_5_BIT_IMM  = (uint64_t*) 0;
uint64_t* SID_6_BIT_IMM  = (uint64_t*) 0;
uint64_t* SID_8_BIT_IMM  = (uint64_t*) 0;
uint64_t* SID_10_BIT_IMM = (uint64_t*) 0;
uint64_t* SID_11_BIT_IMM = (uint64_t*) 0;
uint64_t* SID_12_BIT_IMM = (uint64_t*) 0;
uint64_t* SID_13_BIT_IMM = (uint64_t*) 0;
uint64_t* SID_20_BIT_IMM = (uint64_t*) 0;
uint64_t* SID_21_BIT_IMM = (uint64_t*) 0;
uint64_t* SID_32_BIT_IMM = (uint64_t*) 0;

uint64_t* NID_1_BIT_IMM_0  = (uint64_t*) 0;
uint64_t* NID_12_BIT_IMM_0 = (uint64_t*) 0;

// RISC-U instruction switches

uint64_t* NID_LUI  = (uint64_t*) 0;
uint64_t* NID_ADDI = (uint64_t*) 0;

uint64_t* NID_ADD  = (uint64_t*) 0;
uint64_t* NID_SUB  = (uint64_t*) 0;
uint64_t* NID_MUL  = (uint64_t*) 0;
uint64_t* NID_DIVU = (uint64_t*) 0;
uint64_t* NID_REMU = (uint64_t*) 0;
uint64_t* NID_SLTU = (uint64_t*) 0;

uint64_t* NID_LD = (uint64_t*) 0;
uint64_t* NID_SD = (uint64_t*) 0;
uint64_t* NID_LW = (uint64_t*) 0;
uint64_t* NID_SW = (uint64_t*) 0;

uint64_t* NID_BEQ = (uint64_t*) 0;

uint64_t* NID_JAL  = (uint64_t*) 0;
uint64_t* NID_JALR = (uint64_t*) 0;

uint64_t* NID_ECALL = (uint64_t*) 0;

// RV32I codes missing in RISC-U

uint64_t OP_AUIPC = 23; // 0010111, U format (AUIPC)

uint64_t F3_BNE  = 1; // 001
uint64_t F3_BLT  = 4; // 100
uint64_t F3_BGE  = 5; // 101
uint64_t F3_BLTU = 6; // 110
uint64_t F3_BGEU = 7; // 111

uint64_t F3_LB  = 0; // 000
uint64_t F3_LH  = 1; // 001
uint64_t F3_LBU = 4; // 100
uint64_t F3_LHU = 5; // 101

uint64_t F3_SB = 0; // 000
uint64_t F3_SH = 1; // 001

uint64_t F3_SLL = 1; // 001
uint64_t F3_SLT = 2; // 010
uint64_t F3_XOR = 4; // 100
uint64_t F3_SRL = 5; // 101
uint64_t F3_SRA = 5; // 101
uint64_t F3_OR  = 6; // 110
uint64_t F3_AND = 7; // 111

uint64_t* NID_OP_AUIPC = (uint64_t*) 0;

uint64_t* NID_F3_BNE  = (uint64_t*) 0;
uint64_t* NID_F3_BLT  = (uint64_t*) 0;
uint64_t* NID_F3_BGE  = (uint64_t*) 0;
uint64_t* NID_F3_BLTU = (uint64_t*) 0;
uint64_t* NID_F3_BGEU = (uint64_t*) 0;

uint64_t* NID_F3_LB  = (uint64_t*) 0;
uint64_t* NID_F3_LH  = (uint64_t*) 0;
uint64_t* NID_F3_LBU = (uint64_t*) 0;
uint64_t* NID_F3_LHU = (uint64_t*) 0;

uint64_t* NID_F3_SB = (uint64_t*) 0;
uint64_t* NID_F3_SH = (uint64_t*) 0;

uint64_t* NID_F3_SLL = (uint64_t*) 0;
uint64_t* NID_F3_SLT = (uint64_t*) 0;
uint64_t* NID_F3_XOR = (uint64_t*) 0;
uint64_t* NID_F3_SRL = (uint64_t*) 0;
uint64_t* NID_F3_SRA = (uint64_t*) 0;
uint64_t* NID_F3_OR  = (uint64_t*) 0;
uint64_t* NID_F3_AND = (uint64_t*) 0;

uint64_t* NID_F7_ADD_SLT_XOR_OR_AND_SLL_SRL = (uint64_t*) 0;
uint64_t* NID_F7_SUB_SRA                    = (uint64_t*) 0;

uint64_t* NID_F7_SLL_SRL_ILLEGAL = (uint64_t*) 0;
uint64_t* NID_F7_SRA_ILLEGAL     = (uint64_t*) 0;

// RV32I instruction switches

uint64_t* NID_AUIPC = (uint64_t*) 0;

uint64_t* NID_BNE  = (uint64_t*) 0;
uint64_t* NID_BLT  = (uint64_t*) 0;
uint64_t* NID_BGE  = (uint64_t*) 0;
uint64_t* NID_BLTU = (uint64_t*) 0;
uint64_t* NID_BGEU = (uint64_t*) 0;

uint64_t* NID_LB  = (uint64_t*) 0;
uint64_t* NID_LH  = (uint64_t*) 0;
uint64_t* NID_LBU = (uint64_t*) 0;
uint64_t* NID_LHU = (uint64_t*) 0;

uint64_t* NID_SB = (uint64_t*) 0;
uint64_t* NID_SH = (uint64_t*) 0;

uint64_t* NID_SLTI  = (uint64_t*) 0;
uint64_t* NID_SLTIU = (uint64_t*) 0;
uint64_t* NID_XORI  = (uint64_t*) 0;
uint64_t* NID_ORI   = (uint64_t*) 0;
uint64_t* NID_ANDI  = (uint64_t*) 0;

uint64_t* NID_SLLI = (uint64_t*) 0;
uint64_t* NID_SRLI = (uint64_t*) 0;
uint64_t* NID_SRAI = (uint64_t*) 0;

uint64_t* NID_SLL = (uint64_t*) 0;
uint64_t* NID_SLT = (uint64_t*) 0;
uint64_t* NID_XOR = (uint64_t*) 0;
uint64_t* NID_SRL = (uint64_t*) 0;
uint64_t* NID_SRA = (uint64_t*) 0;

uint64_t* NID_OR  = (uint64_t*) 0;
uint64_t* NID_AND = (uint64_t*) 0;

// RV64I codes missing in RISC-U

uint64_t* SID_FUNCT6 = (uint64_t*) 0;

uint64_t F6_SLL_SRL = 0;  // 000000
uint64_t F6_SRA     = 16; // 010000

uint64_t* NID_F6_SLL_SRL = (uint64_t*) 0;
uint64_t* NID_F6_SRA     = (uint64_t*) 0;

uint64_t OP_IMM_32 = 27; // 0011011, I format
uint64_t OP_OP_32  = 59; // 0111011, I format

uint64_t F3_LWU = 6; // 110

uint64_t* NID_OP_IMM_32 = (uint64_t*) 0;
uint64_t* NID_OP_OP_32  = (uint64_t*) 0;

uint64_t* NID_F3_LWU = (uint64_t*) 0;

// RV64I instruction switches

uint64_t* NID_LWU = (uint64_t*) 0;

uint64_t* NID_ADDIW = (uint64_t*) 0;
uint64_t* NID_SLLIW = (uint64_t*) 0;
uint64_t* NID_SRLIW = (uint64_t*) 0;
uint64_t* NID_SRAIW = (uint64_t*) 0;

uint64_t* NID_ADDW = (uint64_t*) 0;
uint64_t* NID_SUBW = (uint64_t*) 0;
uint64_t* NID_SLLW = (uint64_t*) 0;
uint64_t* NID_SRLW = (uint64_t*) 0;
uint64_t* NID_SRAW = (uint64_t*) 0;

// RV32M codes missing in RISC-U

uint64_t F3_MULH   = 1; // 001
uint64_t F3_MULHSU = 2; // 010
uint64_t F3_MULHU  = 3; // 011
uint64_t F3_DIV    = 4; // 100
uint64_t F3_REM    = 6; // 110

uint64_t* NID_F3_MULH   = (uint64_t*) 0;
uint64_t* NID_F3_MULHSU = (uint64_t*) 0;
uint64_t* NID_F3_MULHU  = (uint64_t*) 0;
uint64_t* NID_F3_DIV    = (uint64_t*) 0;
uint64_t* NID_F3_REM    = (uint64_t*) 0;

// RV32M instruction switches

uint64_t RV32M = 1; // RV32M support

uint64_t* NID_MULH   = (uint64_t*) 0;
uint64_t* NID_MULHSU = (uint64_t*) 0;
uint64_t* NID_MULHU  = (uint64_t*) 0;
uint64_t* NID_DIV    = (uint64_t*) 0;
uint64_t* NID_REM    = (uint64_t*) 0;

// RV64M instruction switches

uint64_t* NID_MULW  = (uint64_t*) 0;
uint64_t* NID_DIVW  = (uint64_t*) 0;
uint64_t* NID_DIVUW = (uint64_t*) 0;
uint64_t* NID_REMW  = (uint64_t*) 0;
uint64_t* NID_REMUW = (uint64_t*) 0;

// ------------------------ GLOBAL VARIABLES -----------------------

uint64_t* eval_core_register_data_flow_nid = (uint64_t*) 0;
uint64_t* eval_core_memory_data_flow_nid   = (uint64_t*) 0;

uint64_t* eval_core_rd_value_nid = (uint64_t*) 0;

uint64_t* eval_core_non_kernel_register_data_flow_nid = (uint64_t*) 0;
uint64_t* eval_core_non_kernel_memory_data_flow_nid   = (uint64_t*) 0;

// ------------------------- INITIALIZATION ------------------------

void init_instruction_sorts() {
  SID_OPCODE = new_bitvec(7, "opcode sort");

  NID_OP_LOAD   = new_constant(OP_CONST, SID_OPCODE, OP_LOAD, 7, "OP_LOAD");
  NID_OP_IMM    = new_constant(OP_CONST, SID_OPCODE, OP_IMM, 7, "OP_IMM");
  NID_OP_STORE  = new_constant(OP_CONST, SID_OPCODE, OP_STORE, 7, "OP_STORE");
  NID_OP_OP     = new_constant(OP_CONST, SID_OPCODE, OP_OP, 7, "OP_OP");
  NID_OP_LUI    = new_constant(OP_CONST, SID_OPCODE, OP_LUI, 7, "OP_LUI");
  NID_OP_BRANCH = new_constant(OP_CONST, SID_OPCODE, OP_BRANCH, 7, "OP_BRANCH");
  NID_OP_JALR   = new_constant(OP_CONST, SID_OPCODE, OP_JALR, 7, "OP_JALR");
  NID_OP_JAL    = new_constant(OP_CONST, SID_OPCODE, OP_JAL, 7, "OP_JAL");
  NID_OP_SYSTEM = new_constant(OP_CONST, SID_OPCODE, OP_SYSTEM, 7, "OP_SYSTEM");

  SID_FUNCT3 = new_bitvec(3, "funct3 sort");

  NID_F3_NOP         = new_constant(OP_CONST, SID_FUNCT3, F3_NOP, 3, "F3_NOP");
  NID_F3_ADDI        = new_constant(OP_CONST, SID_FUNCT3, F3_ADDI, 3, "F3_ADDI");
  NID_F3_ADD_SUB_MUL = new_constant(OP_CONST, SID_FUNCT3, F3_ADD, 3, "F3_ADD_SUB_MUL");
  NID_F3_DIVU        = new_constant(OP_CONST, SID_FUNCT3, F3_DIVU, 3, "F3_DIVU");
  NID_F3_REMU        = new_constant(OP_CONST, SID_FUNCT3, F3_REMU, 3, "F3_REMU");
  NID_F3_SLTU        = new_constant(OP_CONST, SID_FUNCT3, F3_SLTU, 3, "F3_SLTU");
  NID_F3_LD          = new_constant(OP_CONST, SID_FUNCT3, F3_LD, 3, "F3_LD");
  NID_F3_SD          = new_constant(OP_CONST, SID_FUNCT3, F3_SD, 3, "F3_SD");
  NID_F3_LW          = new_constant(OP_CONST, SID_FUNCT3, F3_LW, 3, "F3_LW");
  NID_F3_SW          = new_constant(OP_CONST, SID_FUNCT3, F3_SW, 3, "F3_SW");
  NID_F3_BEQ         = new_constant(OP_CONST, SID_FUNCT3, F3_BEQ, 3, "F3_BEQ");
  NID_F3_JALR        = new_constant(OP_CONST, SID_FUNCT3, F3_JALR, 3, "F3_JALR");
  NID_F3_ECALL       = new_constant(OP_CONST, SID_FUNCT3, F3_ECALL, 3, "F3_ECALL");

  SID_FUNCT7 = new_bitvec(7, "funct7 sort");

  NID_F7_ADD  = new_constant(OP_CONST, SID_FUNCT7, F7_ADD, 7, "F7_ADD");
  NID_F7_MUL  = new_constant(OP_CONST, SID_FUNCT7, F7_MUL, 7, "F7_MUL");
  NID_F7_SUB  = new_constant(OP_CONST, SID_FUNCT7, F7_SUB, 7, "F7_SUB");
  NID_F7_DIVU = new_constant(OP_CONST, SID_FUNCT7, F7_DIVU, 7, "F7_DIVU");
  NID_F7_REMU = new_constant(OP_CONST, SID_FUNCT7, F7_REMU, 7, "F7_REMU");
  NID_F7_SLTU = new_constant(OP_CONST, SID_FUNCT7, F7_SLTU, 7, "F7_SLTU");

  NID_F7_MUL_DIV_REM = NID_F7_MUL;

  SID_FUNCT12 = new_bitvec(12, "funct12 sort");

  NID_F12_ECALL = new_constant(OP_CONST, SID_FUNCT12, F12_ECALL, 12, "F12_ECALL");

  NID_ECALL_I = new_constant(OP_CONST, SID_INSTRUCTION_WORD,
    left_shift(left_shift(left_shift(left_shift(F12_ECALL, 5) + REG_ZR, 3)
      + F3_ECALL, 5) + REG_ZR, 7) + OP_SYSTEM,
    32,
    "ECALL instruction");

  // immediate sorts

  SID_1_BIT_IMM  = new_bitvec(1, "1-bit immediate sort");
  SID_4_BIT_IMM  = new_bitvec(4, "4-bit immediate sort");
  SID_5_BIT_IMM  = new_bitvec(5, "5-bit immediate sort");
  SID_6_BIT_IMM  = new_bitvec(6, "6-bit immediate sort");
  SID_8_BIT_IMM  = new_bitvec(8, "8-bit immediate sort");
  SID_10_BIT_IMM = new_bitvec(10, "10-bit immediate sort");
  SID_11_BIT_IMM = new_bitvec(11, "11-bit immediate sort");
  SID_12_BIT_IMM = new_bitvec(12, "12-bit immediate sort");
  SID_13_BIT_IMM = new_bitvec(13, "13-bit immediate sort");
  SID_20_BIT_IMM = new_bitvec(20, "20-bit immediate sort");
  SID_21_BIT_IMM = new_bitvec(21, "21-bit immediate sort");
  SID_32_BIT_IMM = new_bitvec(32, "32-bit immediate sort");

  NID_1_BIT_IMM_0  = NID_FALSE;
  NID_12_BIT_IMM_0 = new_constant(OP_CONST, SID_12_BIT_IMM, 0, 12, "12 LSBs zeroed");

  // RISC-U instructions

  NID_LUI  = NID_TRUE;
  NID_ADDI = NID_TRUE;

  NID_ADD  = NID_TRUE;
  NID_SUB  = NID_TRUE;
  NID_MUL  = NID_TRUE;
  NID_DIVU = NID_TRUE;
  NID_REMU = NID_TRUE;
  NID_SLTU = NID_TRUE;

  if (IS64BITTARGET) {
    NID_LD = NID_TRUE;
    NID_SD = NID_TRUE;
  } else {
    NID_LD = NID_FALSE;
    NID_SD = NID_FALSE;
  }

  NID_LW = NID_TRUE;
  NID_SW = NID_TRUE;

  NID_BEQ = NID_TRUE;

  NID_JAL  = NID_TRUE;
  NID_JALR = NID_TRUE;

  NID_ECALL = NID_TRUE;

  // RV32I codes missing in RISC-U

  NID_OP_AUIPC = new_constant(OP_CONST, SID_OPCODE, OP_AUIPC, 7, "OP_AUIPC");

  NID_F3_BNE  = new_constant(OP_CONST, SID_FUNCT3, F3_BNE, 3, "F3_BNE");
  NID_F3_BLT  = new_constant(OP_CONST, SID_FUNCT3, F3_BLT, 3, "F3_BLT");
  NID_F3_BGE  = new_constant(OP_CONST, SID_FUNCT3, F3_BGE, 3, "F3_BGE");
  NID_F3_BLTU = new_constant(OP_CONST, SID_FUNCT3, F3_BLTU, 3, "F3_BLTU");
  NID_F3_BGEU = new_constant(OP_CONST, SID_FUNCT3, F3_BGEU, 3, "F3_BGEU");

  NID_F3_LB  = new_constant(OP_CONST, SID_FUNCT3, F3_LB, 3, "F3_LB");
  NID_F3_LH  = new_constant(OP_CONST, SID_FUNCT3, F3_LH, 3, "F3_LH");
  NID_F3_LBU = new_constant(OP_CONST, SID_FUNCT3, F3_LBU, 3, "F3_LBU");
  NID_F3_LHU = new_constant(OP_CONST, SID_FUNCT3, F3_LHU, 3, "F3_LHU");

  NID_F3_SB = new_constant(OP_CONST, SID_FUNCT3, F3_SB, 3, "F3_SB");
  NID_F3_SH = new_constant(OP_CONST, SID_FUNCT3, F3_SH, 3, "F3_SH");

  NID_F3_SLL = new_constant(OP_CONST, SID_FUNCT3, F3_SLL, 3, "F3_SLL");
  NID_F3_SLT = new_constant(OP_CONST, SID_FUNCT3, F3_SLT, 3, "F3_SLT");
  NID_F3_XOR = new_constant(OP_CONST, SID_FUNCT3, F3_XOR, 3, "F3_XOR");
  NID_F3_SRL = new_constant(OP_CONST, SID_FUNCT3, F3_SRL, 3, "F3_SRL");
  NID_F3_SRA = new_constant(OP_CONST, SID_FUNCT3, F3_SRA, 3, "F3_SRA");
  NID_F3_OR  = new_constant(OP_CONST, SID_FUNCT3, F3_OR, 3, "F3_OR");
  NID_F3_AND = new_constant(OP_CONST, SID_FUNCT3, F3_AND, 3, "F3_AND");

  NID_F7_ADD_SLT_XOR_OR_AND_SLL_SRL = NID_F7_ADD;
  NID_F7_SUB_SRA                    = NID_F7_SUB;

  NID_F7_SLL_SRL_ILLEGAL = new_constant(OP_CONST, SID_FUNCT7, F7_ADD + 1, 7, "F7_SLL_SRL_ILLEGAL");
  NID_F7_SRA_ILLEGAL     = new_constant(OP_CONST, SID_FUNCT7, F7_SUB + 1, 7, "F7_SRA_ILLEGAL");

  // RV32I instruction switches

  NID_AUIPC = NID_TRUE;

  NID_BNE  = NID_TRUE;
  NID_BLT  = NID_TRUE;
  NID_BGE  = NID_TRUE;
  NID_BLTU = NID_TRUE;
  NID_BGEU = NID_TRUE;

  NID_LB  = NID_TRUE;
  NID_LH  = NID_TRUE;
  NID_LBU = NID_TRUE;
  NID_LHU = NID_TRUE;

  NID_SB = NID_TRUE;
  NID_SH = NID_TRUE;

  NID_SLTI  = NID_TRUE;
  NID_SLTIU = NID_TRUE;
  NID_XORI  = NID_TRUE;
  NID_ORI   = NID_TRUE;
  NID_ANDI  = NID_TRUE;

  NID_SLLI = NID_TRUE;
  NID_SRLI = NID_TRUE;
  NID_SRAI = NID_TRUE;

  NID_SLL = NID_TRUE;
  NID_SLT = NID_TRUE;
  NID_XOR = NID_TRUE;
  NID_SRL = NID_TRUE;
  NID_SRA = NID_TRUE;

  NID_OR  = NID_TRUE;
  NID_AND = NID_TRUE;

  // RV64I codes missing in RISC-U

  if (IS64BITTARGET) {
    SID_FUNCT6 = new_bitvec(6, "funct6 sort");

    NID_F6_SLL_SRL = new_constant(OP_CONST, SID_FUNCT6, F6_SLL_SRL, 6, "F6_SLL_SRL");
    NID_F6_SRA     = new_constant(OP_CONST, SID_FUNCT6, F6_SRA, 6, "F6_SRA");

    NID_OP_IMM_32 = new_constant(OP_CONST, SID_OPCODE, OP_IMM_32, 7, "OP_IMM_32");
    NID_OP_OP_32  = new_constant(OP_CONST, SID_OPCODE, OP_OP_32, 7, "OP_OP_32");
  }

  // TODO: only include on 64-bit targets

  NID_F3_LWU = new_constant(OP_CONST, SID_FUNCT3, F3_LWU, 3, "F3_LWU");

  // RV64I instruction switches

  if (IS64BITTARGET) {
    NID_LWU = NID_TRUE;

    NID_ADDIW = NID_TRUE;
    NID_SLLIW = NID_TRUE;
    NID_SRLIW = NID_TRUE;
    NID_SRAIW = NID_TRUE;

    NID_ADDW = NID_FALSE;
    NID_SUBW = NID_FALSE;
    NID_SLLW = NID_FALSE;
    NID_SRLW = NID_FALSE;
    NID_SRAW = NID_FALSE;
  } else {
    NID_LWU = NID_FALSE;

    NID_ADDIW = NID_FALSE;
    NID_SLLIW = NID_FALSE;
    NID_SRLIW = NID_FALSE;
    NID_SRAIW = NID_FALSE;

    NID_ADDW = NID_FALSE;
    NID_SUBW = NID_FALSE;
    NID_SLLW = NID_FALSE;
    NID_SRLW = NID_FALSE;
    NID_SRAW = NID_FALSE;
  }

  // RV32M codes missing in RISC-U

  NID_F3_MULH   = new_constant(OP_CONST, SID_FUNCT3, F3_MULH, 3, "F3_MULH");
  NID_F3_MULHSU = new_constant(OP_CONST, SID_FUNCT3, F3_MULHSU, 3, "F3_MULHSU");
  NID_F3_MULHU  = new_constant(OP_CONST, SID_FUNCT3, F3_MULHU, 3, "F3_MULHU");
  NID_F3_DIV    = new_constant(OP_CONST, SID_FUNCT3, F3_DIV, 3, "F3_DIV");
  NID_F3_REM    = new_constant(OP_CONST, SID_FUNCT3, F3_REM, 3, "F3_REM");

  // RV32M instruction switches

  if (RV32M) {
    NID_MUL    = NID_TRUE;
    NID_MULH   = NID_TRUE;
    NID_MULHSU = NID_TRUE;
    NID_MULHU  = NID_TRUE;
    NID_DIV    = NID_TRUE;
    NID_REM    = NID_TRUE;
  } else {
    NID_MUL    = NID_FALSE;
    NID_MULH   = NID_FALSE;
    NID_MULHSU = NID_FALSE;
    NID_MULHU  = NID_FALSE;
    NID_DIV    = NID_FALSE;
    NID_REM    = NID_FALSE;
  }

  // RV64M instruction switches

  if (IS64BITTARGET) {
    NID_MULW  = NID_TRUE;
    NID_DIVW  = NID_TRUE;
    NID_DIVUW = NID_TRUE;
    NID_REMW  = NID_TRUE;
    NID_REMUW = NID_TRUE;
  } else {
    NID_MULW  = NID_FALSE;
    NID_DIVW  = NID_FALSE;
    NID_DIVUW = NID_FALSE;
    NID_REMW  = NID_FALSE;
    NID_REMUW = NID_FALSE;
  }
}

// -----------------------------------------------------------------
// ----------------------------- CORE ------------------------------
// -----------------------------------------------------------------

void new_core_state();

// ------------------------ GLOBAL VARIABLES -----------------------

uint64_t* initial_core_pc_nid = (uint64_t*) 0;

uint64_t* state_core_pc_nid = (uint64_t*) 0;
uint64_t* init_core_pc_nid  = (uint64_t*) 0;

uint64_t* eval_core_pc_nid = (uint64_t*) 0;
uint64_t* next_core_pc_nid = (uint64_t*) 0;

uint64_t* eval_core_non_kernel_pc_nid = (uint64_t*) 0;

// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~
// -----------------------------------------------------------------
// ----------------------    R U N T I M E    ----------------------
// -----------------------------------------------------------------
// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~

// -----------------------------------------------------------------
// ------------------------ MODEL GENERATOR ------------------------
// -----------------------------------------------------------------

uint64_t* state_property(uint64_t* good_nid, uint64_t* bad_nid, char* symbol, char* comment);

void kernel(uint64_t* pc_nid, uint64_t* ir_nid, uint64_t* memory_nid);

void rotor();

void output_model();

uint64_t selfie_model();

// ------------------------ GLOBAL CONSTANTS -----------------------

uint64_t REUSE_LINES = 1; // flag for reusing lines

uint64_t SYNTHESIZE = 1; // flag for synthesizing versus analyzing code

// ------------------------ GLOBAL VARIABLES -----------------------

char*    model_name = (char*) 0; // name of model file
uint64_t model_fd   = 0;         // file descriptor of open model file

uint64_t w = 0; // number of written characters

uint64_t bad_exit_code = 0; // model for this exit code

uint64_t* is_instruction_known_nid    = (uint64_t*) 0;
uint64_t* illegal_instruction_nid     = (uint64_t*) 0;
uint64_t* next_fetch_unaligned_nid    = (uint64_t*) 0;
uint64_t* next_fetch_seg_faulting_nid = (uint64_t*) 0;
uint64_t* load_seg_faulting_nid       = (uint64_t*) 0;
uint64_t* store_seg_faulting_nid      = (uint64_t*) 0;
uint64_t* stack_seg_faulting_nid      = (uint64_t*) 0;
uint64_t* division_by_zero_nid        = (uint64_t*) 0;
uint64_t* exclude_a0_from_rd_nid      = (uint64_t*) 0;

uint64_t* brk_seg_faulting_nid    = (uint64_t*) 0;
uint64_t* openat_seg_faulting_nid = (uint64_t*) 0;
uint64_t* read_seg_faulting_nid   = (uint64_t*) 0;
uint64_t* write_seg_faulting_nid  = (uint64_t*) 0;
uint64_t* is_syscall_id_known_nid = (uint64_t*) 0;
uint64_t* bad_exit_code_nid       = (uint64_t*) 0;

uint64_t* bad_memory_nid = (uint64_t*) 0;

// ------------------------- INITIALIZATION ------------------------

void init_model_generator() {
  init_model();

  init_interface_sorts();
  init_interface_memory();
  init_interface_kernel();

  init_register_file_sorts();
  init_memory_sorts();
  init_instruction_sorts();
}

// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~
// -----------------------------------------------------------------
// -----------------------     M O D E L     -----------------------
// -----------------------------------------------------------------
// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~

uint64_t are_lines_equal(uint64_t* left_line, uint64_t* right_line) {
  // assert: pointer equivalence iff structural equivalence

  if (get_op(left_line) == get_op(right_line))
    if (get_sid(left_line) == get_sid(right_line))
      if (get_arg1(left_line) == get_arg1(right_line))
        if (get_arg2(left_line) == get_arg2(right_line))
          if (get_arg3(left_line) == get_arg3(right_line))
            return 1;

  return 0;
}

uint64_t* find_equal_line(uint64_t* line) {
  uint64_t* pred_line;

  pred_line = last_line;

  while (pred_line) {
    if (are_lines_equal(pred_line, line))
      return pred_line;

    pred_line = get_pred(pred_line);
  }

  return UNUSED;
}

uint64_t* new_line(char* op, uint64_t* sid, uint64_t* arg1, uint64_t* arg2, uint64_t* arg3, char* comment) {
  uint64_t* new_line;
  uint64_t* old_line;

  // invariant: pointer equivalence iff structural equivalence

  if (unused_line)
    new_line = unused_line;
  else
    new_line = allocate_line();

  set_op(new_line, op);
  set_sid(new_line, sid);
  set_arg1(new_line, arg1);
  set_arg2(new_line, arg2);
  set_arg3(new_line, arg3);
  set_comment(new_line, comment);
  set_reuse(new_line, 0);

  if (REUSE_LINES)
    old_line = find_equal_line(new_line);
  else
    old_line = (uint64_t*) 0;

  if (old_line) {
    unused_line = new_line;

    set_reuse(old_line, get_reuse(old_line) + 1);

    // invariant: pointer equivalence iff structural equivalence

    return old_line;
  } else {
    unused_line = UNUSED;

    set_pred(new_line, last_line);

    last_line = new_line;

    number_of_lines = number_of_lines + 1;

    // invariant: pointer equivalence iff structural equivalence

    return new_line;
  }
}

uint64_t* new_bitvec(uint64_t size_in_bits, char* comment) {
  return new_line(OP_SORT, UNUSED, (uint64_t*) BITVEC, (uint64_t*) size_in_bits, UNUSED, comment);
}

uint64_t* new_array(uint64_t* size_sid, uint64_t* element_sid, char* comment) {
  return new_line(OP_SORT, UNUSED, (uint64_t*) ARRAY, size_sid, element_sid, comment);
}

uint64_t* new_constant(char* op, uint64_t* sid, uint64_t constant, uint64_t digits, char* comment) {
  return new_line(op, sid, (uint64_t*) constant, (uint64_t*) digits, UNUSED, comment);
}

uint64_t* new_input(char* op, uint64_t* sid, char* symbol, char* comment) {
  return new_line(op, sid, (uint64_t*) symbol, UNUSED, UNUSED, comment);
}

uint64_t* new_ext(char* op, uint64_t* sid, uint64_t* value_nid, uint64_t w, char* comment) {
  return new_line(op, sid, value_nid, (uint64_t*) w, UNUSED, comment);
}

uint64_t* new_slice(uint64_t* sid, uint64_t* value_nid, uint64_t u, uint64_t l, char* comment) {
  return new_line(OP_SLICE, sid, value_nid, (uint64_t*) u, (uint64_t*) l, comment);
}

uint64_t* new_unary(char* op, uint64_t* sid, uint64_t* value_nid, char* comment) {
  return new_line(op, sid, value_nid, UNUSED, UNUSED, comment);
}

uint64_t* new_unary_boolean(char* op, uint64_t* value_nid, char* comment) {
  return new_unary(op, SID_BOOLEAN, value_nid, comment);
}

uint64_t* new_binary(char* op, uint64_t* sid, uint64_t* left_nid, uint64_t* right_nid, char* comment) {
  return new_line(op, sid, left_nid, right_nid, UNUSED, comment);
}

uint64_t* new_binary_boolean(char* op, uint64_t* left_nid, uint64_t* right_nid, char* comment) {
  return new_binary(op, SID_BOOLEAN, left_nid, right_nid, comment);
}

uint64_t* new_ternary(char* op, uint64_t* sid, uint64_t* first_nid, uint64_t* second_nid, uint64_t* third_nid, char* comment) {
  return new_line(op, sid, first_nid, second_nid, third_nid, comment);
}

uint64_t* new_property(char* op, uint64_t* condition_nid, char* symbol, char* comment) {
  return new_line(op, UNUSED, condition_nid, (uint64_t*) symbol, UNUSED, comment);
}

void print_nid(uint64_t nid, uint64_t* line) {
  set_nid(line, nid);
  w = w + dprintf(output_fd, "%lu", nid);
}

uint64_t print_sort(uint64_t nid, uint64_t* line) {
  if ((char*) get_arg1(line) == ARRAY) {
    nid = print_referenced_line(nid, get_arg2(line));
    nid = print_referenced_line(nid, get_arg3(line));
  }
  print_nid(nid, line);
  w = w + dprintf(output_fd, " %s", OP_SORT);
  if ((char*) get_arg1(line) == BITVEC)
    w = w + dprintf(output_fd, " %s %lu", BITVEC, (uint64_t) get_arg2(line));
  else
    // assert: theory of bitvector arrays
    w = w + dprintf(output_fd, " %s %lu %lu", ARRAY, get_nid(get_arg2(line)), get_nid(get_arg3(line)));
  return nid;
}

uint64_t print_constant(uint64_t nid, uint64_t* line) {
  nid = print_referenced_line(nid, get_sid(line));
  print_nid(nid, line);
  if (get_op(line) == OP_CONSTD) {
    if ((uint64_t) get_arg1(line) == 0)
      w = w + dprintf(output_fd, " zero %lu", get_nid(get_sid(line)));
    else if ((uint64_t) get_arg1(line) == 1)
      w = w + dprintf(output_fd, " one %lu", get_nid(get_sid(line)));
    else
      w = w + dprintf(output_fd, " %s %lu %ld", get_op(line), get_nid(get_sid(line)), (uint64_t) get_arg1(line));
  } else if (get_op(line) == OP_CONST)
    w = w + dprintf(output_fd, " %s %lu %s", get_op(line), get_nid(get_sid(line)),
      itoa((uint64_t) get_arg1(line), integer_buffer, 2, 0, (uint64_t) get_arg2(line)));
  else
    // assert: get_op(line) == OP_CONSTH
    w = w + dprintf(output_fd, " %s %lu %s", get_op(line), get_nid(get_sid(line)),
      itoa((uint64_t) get_arg1(line), integer_buffer, 16, 0, (uint64_t) get_arg2(line)));
  return nid;
}

uint64_t print_input(uint64_t nid, uint64_t* line) {
  nid = print_referenced_line(nid, get_sid(line));
  print_nid(nid, line);
  w = w + dprintf(output_fd, " %s %lu %s", get_op(line), get_nid(get_sid(line)), (char*) get_arg1(line));
  return nid;
}

uint64_t print_ext(uint64_t nid, uint64_t* line) {
  nid = print_referenced_line(nid, get_sid(line));
  nid = print_referenced_line(nid, get_arg1(line));
  print_nid(nid, line);
  w = w + dprintf(output_fd, " %s %lu %lu %lu",
    get_op(line), get_nid(get_sid(line)), get_nid(get_arg1(line)), (uint64_t) get_arg2(line));
  return nid;
}

uint64_t print_slice(uint64_t nid, uint64_t* line) {
  nid = print_referenced_line(nid, get_sid(line));
  nid = print_referenced_line(nid, get_arg1(line));
  print_nid(nid, line);
  w = w + dprintf(output_fd, " %s %lu %lu %lu %lu",
    OP_SLICE, get_nid(get_sid(line)), get_nid(get_arg1(line)), (uint64_t) get_arg2(line), (uint64_t) get_arg3(line));
  return nid;
}

uint64_t print_unary_op(uint64_t nid, uint64_t* line) {
  nid = print_referenced_line(nid, get_sid(line));
  nid = print_referenced_line(nid, get_arg1(line));
  print_nid(nid, line);
  w = w + dprintf(output_fd, " %s %lu %lu",
    get_op(line), get_nid(get_sid(line)), get_nid(get_arg1(line)));
  return nid;
}

uint64_t print_binary_op(uint64_t nid, uint64_t* line) {
  nid = print_referenced_line(nid, get_sid(line));
  nid = print_referenced_line(nid, get_arg1(line));
  nid = print_referenced_line(nid, get_arg2(line));
  print_nid(nid, line);
  w = w + dprintf(output_fd, " %s %lu %lu %lu",
    get_op(line), get_nid(get_sid(line)), get_nid(get_arg1(line)), get_nid(get_arg2(line)));
  return nid;
}

uint64_t print_ternary_op(uint64_t nid, uint64_t* line) {
  nid = print_referenced_line(nid, get_sid(line));
  nid = print_referenced_line(nid, get_arg1(line));
  nid = print_referenced_line(nid, get_arg2(line));
  nid = print_referenced_line(nid, get_arg3(line));
  print_nid(nid, line);
  w = w + dprintf(output_fd, " %s %lu %lu %lu %lu",
    get_op(line), get_nid(get_sid(line)), get_nid(get_arg1(line)), get_nid(get_arg2(line)), get_nid(get_arg3(line)));
  return nid;
}

uint64_t print_constraint(uint64_t nid, uint64_t* line) {
  nid = print_referenced_line(nid, get_arg1(line));
  print_nid(nid, line);
  w = w + dprintf(output_fd, " %s %lu %s", get_op(line), get_nid(get_arg1(line)), (char*) get_arg2(line));
  return nid;
}

void print_comment(uint64_t* line) {
  if (get_comment(line) != NOCOMMENT) {
    if (get_reuse(line) > 0)
      w = w + dprintf(output_fd, " ; %s [reused %lu time(s)]", get_comment(line), get_reuse(line));
    else
      w = w + dprintf(output_fd, " ; %s", get_comment(line));
  } else if (get_reuse(line) > 0)
    w = w + dprintf(output_fd, " ; [reused %lu time(s)]", get_reuse(line));
  w = w + dprintf(output_fd, "\n");
}

uint64_t is_constant_op(char* op) {
  if (op == OP_CONSTD)
    return 1;
  else if (op == OP_CONST)
    return 1;
  else if (op == OP_CONSTH)
    return 1;
  else
    return 0;
}

uint64_t is_input_op(char* op) {
  if (op == OP_INPUT)
    return 1;
  else if (op == OP_STATE)
    return 1;
  else
    return 0;
}

uint64_t is_unary_op(char* op) {
  if (op == OP_NOT)
    return 1;
  else if (op == OP_INC)
    return 1;
  else if (op == OP_DEC)
    return 1;
  else if (op == OP_NEG)
    return 1;
  else
    return 0;
}

uint64_t print_referenced_line(uint64_t nid, uint64_t* line) {
  char* op;

  op = get_op(line);

  if (get_nid(line) > 0)
    // print lines only once
    return nid;
  else if (op == OP_SORT)
    nid = print_sort(nid, line);
  else if (is_constant_op(op))
    nid = print_constant(nid, line);
  else if (is_input_op(op))
    nid = print_input(nid, line);
  else if (op == OP_SEXT)
    nid = print_ext(nid, line);
  else if (op == OP_UEXT)
    nid = print_ext(nid, line);
  else if (op == OP_SLICE)
    nid = print_slice(nid, line);
  else if (is_unary_op(op))
    nid = print_unary_op(nid, line);
  else if (op == OP_ITE)
    nid = print_ternary_op(nid, line);
  else if (op == OP_WRITE)
    nid = print_ternary_op(nid, line);
  else if (op == OP_BAD)
    nid = print_constraint(nid, line);
  else if (op == OP_CONSTRAINT)
    nid = print_constraint(nid, line);
  else
    nid = print_binary_op(nid, line);
  print_comment(line);
  return nid + 1;
}

void print_line(uint64_t* line) {
  if (get_nid(line) > 0)
    // print lines only once but mention reuse at top level
    w = w + dprintf(output_fd, "; skipping line reusing %lu\n", get_nid(line));
  else
    current_nid = print_referenced_line(current_nid, line);
}

void print_break(char* comment) {
  uint64_t order_of_magnitude;

  w = w + dprintf(output_fd, comment);

  order_of_magnitude = ten_to_the_power_of(log_ten(current_nid));

  current_nid = current_nid - current_nid % order_of_magnitude + order_of_magnitude;
}

void print_aligned_break(char* comment, uint64_t alignment) {
  print_break(comment);

  if (log_ten(current_nid) < alignment)
    current_nid = ten_to_the_power_of(alignment);
}

char* format_comment(char* comment, uint64_t value) {
  sprintf(string_buffer, comment, value);
  return string_copy(string_buffer);
}

char* format_binary(uint64_t value, uint64_t alignment) {
  return string_copy(itoa(value, integer_buffer, 2, 0, alignment));
}

char* format_decimal(uint64_t value) {
  return format_comment("%ld", value);
}

char* format_hexadecimal(uint64_t value) {
  return format_comment("%lX", value);
}

char* format_comment_binary(char* comment, uint64_t value) {
  sprintf(string_buffer, "%s %s", comment, format_binary(value, 0));
  return string_copy(string_buffer);
}

// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~
// -----------------------------------------------------------------
// -------------------     I N T E R F A C E     -------------------
// -----------------------------------------------------------------
// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~

void print_interface_sorts() {
  print_line(SID_BOOLEAN);

  print_line(SID_BYTE);
  print_line(SID_HALF_WORD);
  print_line(SID_SINGLE_WORD);
  if (IS64BITTARGET)
    print_line(SID_DOUBLE_WORD);

  print_break("\n; machine constants\n\n");

  print_line(NID_FALSE);
  print_line(NID_TRUE);

  print_break("\n");

  print_line(NID_BYTE_0);

  print_break("\n");

  print_line(NID_SINGLE_WORD_0);
  print_line(NID_SINGLE_WORD_1);
  print_line(NID_SINGLE_WORD_2);
  print_line(NID_SINGLE_WORD_3);
  print_line(NID_SINGLE_WORD_4);
  print_line(NID_SINGLE_WORD_5);
  print_line(NID_SINGLE_WORD_6);
  print_line(NID_SINGLE_WORD_7);
  print_line(NID_SINGLE_WORD_8);

  print_line(NID_SINGLE_WORD_MINUS_1);

  if (IS64BITTARGET) {
    print_break("\n");

    print_line(NID_DOUBLE_WORD_0);
    print_line(NID_DOUBLE_WORD_1);
    print_line(NID_DOUBLE_WORD_2);
    print_line(NID_DOUBLE_WORD_3);
    print_line(NID_DOUBLE_WORD_4);
    print_line(NID_DOUBLE_WORD_5);
    print_line(NID_DOUBLE_WORD_6);
    print_line(NID_DOUBLE_WORD_7);
    print_line(NID_DOUBLE_WORD_8);

    print_line(NID_DOUBLE_WORD_MINUS_1);
  }
}

// -----------------------------------------------------------------
// ---------------------------- KERNEL -----------------------------
// -----------------------------------------------------------------

void print_interface_kernel() {
  print_break("\n; kernel interface\n\n");

  print_line(NID_EXIT_SYSCALL_ID);
  print_line(NID_BRK_SYSCALL_ID);
  print_line(NID_OPENAT_SYSCALL_ID);
  print_line(NID_READ_SYSCALL_ID);
  print_line(NID_WRITE_SYSCALL_ID);
}

void new_kernel_state(uint64_t bytes_to_read) {
  state_program_break_nid = new_input(OP_STATE, SID_MACHINE_WORD, "program-break", "program break");
  init_program_break_nid  = new_binary(OP_INIT, SID_MACHINE_WORD, state_program_break_nid,
    NID_HEAP_START, "initial program break is start of heap segment");

  state_file_descriptor_nid = new_input(OP_STATE, SID_MACHINE_WORD, "file-descriptor", "file descriptor");
  init_file_descriptor_nid  = new_binary(OP_INIT, SID_MACHINE_WORD, state_file_descriptor_nid,
    NID_MACHINE_WORD_0, "initial file descriptor is zero");

  readable_bytes_nid = new_constant(OP_CONSTD, SID_MACHINE_WORD,
    bytes_to_read,
    0,
    "read capacity in bytes");

  state_readable_bytes_nid = new_input(OP_STATE, SID_MACHINE_WORD, "readable-bytes", "readable bytes");
  init_readable_bytes_nid  = new_binary(OP_INIT, SID_MACHINE_WORD, state_readable_bytes_nid,
    readable_bytes_nid, "number of readable bytes");

  state_read_bytes_nid = new_input(OP_STATE, SID_MACHINE_WORD, "read-bytes", "bytes read in active read system call");
  init_read_bytes_nid  = new_binary(OP_INIT, SID_MACHINE_WORD, state_read_bytes_nid,
    NID_MACHINE_WORD_0, "initially zero read bytes");
}

// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~
// -----------------------------------------------------------------
// -----------------    A R C H I T E C T U R E    -----------------
// -----------------------------------------------------------------
// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~

// -----------------------------------------------------------------
// --------------------------- REGISTERS ---------------------------
// -----------------------------------------------------------------

void print_register_sorts() {
  print_break("\n; register sorts\n\n");

  print_line(SID_REGISTER_ADDRESS);
  print_line(SID_REGISTER_STATE);
}

uint64_t* load_register_value(uint64_t* reg_nid, char* comment) {
  return new_binary(OP_READ, SID_MACHINE_WORD, state_register_file_nid, reg_nid, comment);
}

uint64_t* store_register_value(uint64_t* reg_nid, uint64_t* value_nid, uint64_t* register_file_nid, char* comment) {
  return new_ternary(OP_WRITE, SID_REGISTER_STATE, register_file_nid, reg_nid, value_nid, comment);
}

void new_register_file_state() {
  uint64_t  reg;
  uint64_t* reg_nid;
  uint64_t  value;
  uint64_t* value_nid;

  state_register_file_nid = new_input(OP_STATE, SID_REGISTER_STATE,
    "zeroed-register-file", "zeroed register file");

  zeroed_register_file_nid = new_binary(OP_INIT, SID_REGISTER_STATE,
    state_register_file_nid, NID_MACHINE_WORD_0, "zeroing register file");

  if (SYNTHESIZE)
    initial_register_file_nid =
      store_register_value(
        NID_SP,
        new_unary(OP_DEC, SID_MACHINE_WORD, NID_STACK_END, "end of stack segment - 1"),
        state_register_file_nid,
        "write initial sp value");
  else {
    initial_register_file_nid = state_register_file_nid;

    reg = 0;

    while (reg < 32) {
      value = *(get_regs(current_context) + reg);

      if (value != 0) {
        // skipping zero as initial value
        value_nid = new_constant(OP_CONSTH, SID_MACHINE_WORD,
          value,
          0,
          format_comment("initial register value 0x%lX", value));
        // for reuse creating register address exactly as above in register sorts
        reg_nid = new_constant(OP_CONST, SID_REGISTER_ADDRESS,
          reg,
          5,
          format_comment("%s", *(REGISTERS + reg)));
        initial_register_file_nid =
          store_register_value(reg_nid, value_nid,
            initial_register_file_nid, "write initial register value");
      }

      reg = reg + 1;
    }
  }

  if (initial_register_file_nid != state_register_file_nid) {
    state_register_file_nid = new_input(OP_STATE, SID_REGISTER_STATE,
      "initialized-register-file", "initialized register file");

    init_register_file_nid = new_binary(OP_INIT, SID_REGISTER_STATE,
      state_register_file_nid, initial_register_file_nid, "initializing registers");
  } else
    init_register_file_nid = zeroed_register_file_nid;
}

void print_register_file_state() {
  print_break("\n; zeroed register file\n\n");

  print_line(zeroed_register_file_nid);

  if (init_register_file_nid != zeroed_register_file_nid) {
    if (SYNTHESIZE)
      print_break("\n; initializing sp\n\n");
    else
      print_aligned_break("\n; initializing registers\n\n", log_ten(32 * 3 + 1) + 1);

    print_line(initial_register_file_nid);

    print_break("\n; initialized register file\n\n");

    print_line(init_register_file_nid);
  }
}

// -----------------------------------------------------------------
// ---------------------------- MEMORY -----------------------------
// -----------------------------------------------------------------

void print_memory_sorts() {
  print_break("\n; memory sorts\n\n");

  print_line(SID_CODE_ADDRESS);
  print_line(SID_CODE_STATE);

  print_break("\n");

  if (ISBYTEMEMORY)
    print_line(SID_MEMORY_ADDRESS);
  else if (IS64BITTARGET)
    print_line(SID_MEMORY_ADDRESS);

  print_line(SID_MEMORY_STATE);
}

void new_segmentation() {
  NID_CODE_START = new_constant(OP_CONSTH, SID_MACHINE_WORD,
    code_start,
    8,
    format_comment("start of code segment @ 0x%08lX", code_start));

  NID_CODE_END = new_constant(OP_CONSTH, SID_MACHINE_WORD,
    code_start + code_size,
    8,
    format_comment("end of code segment accommodating %lu instructions", code_size / INSTRUCTIONSIZE));

  NID_DATA_START = new_constant(OP_CONSTH, SID_MACHINE_WORD,
    data_start,
    8,
    format_comment("start of data segment @ 0x%08lX", data_start));

  NID_DATA_END = new_constant(OP_CONSTH, SID_MACHINE_WORD,
    data_start + data_size,
    8,
    format_comment("end of data segment accommodating %lu bytes", data_size));

  NID_HEAP_START = new_constant(OP_CONSTH, SID_MACHINE_WORD,
    heap_start,
    8,
    format_comment("start of heap segment @ 0x%08lX", heap_start));

  NID_HEAP_END = new_constant(OP_CONSTH, SID_MACHINE_WORD,
    heap_start + heap_size,
    8,
    format_comment("static end of heap segment accommodating %lu bytes", heap_size));

  // assert: stack_start >= heap_start + heap_size > 0

  NID_STACK_START = new_constant(OP_CONSTH, SID_MACHINE_WORD,
    stack_start,
    8,
    format_comment("static start of stack segment @ 0x%08lX", stack_start));

  if (IS64BITTARGET)
    NID_STACK_END = new_constant(OP_CONSTH, SID_MACHINE_WORD,
      stack_start + stack_size,
      8,
      format_comment("end of stack segment accommodating %lu bytes", stack_size));
  else
    // force wrap-around
    NID_STACK_END = new_constant(OP_CONSTH, SID_MACHINE_WORD,
      0,
      8,
      format_comment("end of stack segment accommodating %lu bytes", stack_size));
}

void print_segmentation() {
  print_break("\n; segmentation\n\n");

  print_line(NID_CODE_START);
  print_line(NID_CODE_END);

  print_line(NID_DATA_START);
  print_line(NID_DATA_END);

  print_line(NID_HEAP_START);
  print_line(NID_HEAP_END);

  print_line(NID_STACK_START);
  print_line(NID_STACK_END);
}

void new_code_segment() {
  uint64_t  number_of_hex_digits;
  uint64_t* laddr_nid;
  uint64_t* ir_nid;

  state_code_segment_nid = new_input(OP_STATE, SID_CODE_STATE, "code-segment", "code segment");

  if (SYNTHESIZE == 0) {
    zeroed_code_segment_nid = new_binary(OP_INIT, SID_CODE_STATE,
      state_code_segment_nid, NID_SINGLE_WORD_0, "zeroing code segment");

    number_of_hex_digits = round_up(CODE_ADDRESS_SPACE, 4) / 4;

    initial_code_segment_nid = state_code_segment_nid;

    REUSE_LINES = 1; // TODO: turn off via console argument

    pc = code_start;

    while (pc < code_start + code_size) {
      fetch();

      if (ir != 0) {
        // skipping zero as instruction
        ir_nid = new_constant(OP_CONST, SID_INSTRUCTION_WORD,
          ir,
          32,
          format_comment("code 0x%08lX", ir));
        laddr_nid = new_constant(OP_CONSTH, SID_CODE_ADDRESS,
          (pc - code_start) / INSTRUCTIONSIZE,
          number_of_hex_digits,
          format_comment("vaddr 0x%lX", pc));
        initial_code_segment_nid = new_ternary(OP_WRITE, SID_CODE_STATE,
          initial_code_segment_nid,
          laddr_nid,
          ir_nid,
          "load code");
      }

      pc = pc + INSTRUCTIONSIZE;
    }

    REUSE_LINES = 1;

    if (initial_code_segment_nid != state_code_segment_nid) {
      state_code_segment_nid = new_input(OP_STATE, SID_CODE_STATE,
        "loaded-code-segment", "loaded code segment");

      init_code_segment_nid = new_binary(OP_INIT, SID_CODE_STATE,
        state_code_segment_nid, initial_code_segment_nid, "loaded code");
    } else
      init_code_segment_nid = zeroed_code_segment_nid;

    next_code_segment_nid = new_binary(OP_NEXT, SID_CODE_STATE,
      state_code_segment_nid, state_code_segment_nid, "read-only code segment");
  }
}

void print_code_segment() {
  if (SYNTHESIZE) {
    print_break("\n; uninitialized code segment\n\n");

    print_line(state_code_segment_nid);
  } else {
    print_break("\n; zeroed code segment\n\n");

    print_line(zeroed_code_segment_nid);

    if (initial_code_segment_nid != state_code_segment_nid) {
      print_aligned_break("\n; loading code\n\n",
        log_ten(code_size / INSTRUCTIONSIZE * 3 + 1) + 1);

      print_line(initial_code_segment_nid);

      print_break("\n; loaded code segment\n\n");

      print_line(init_code_segment_nid);
    }

    print_line(next_code_segment_nid);
  }
}

void new_memory_state() {
  uint64_t  number_of_hex_digits;
  uint64_t  vaddr;
  uint64_t  data;
  uint64_t* data_nid;
  uint64_t* vaddr_nid;
  uint64_t* laddr_nid;

  state_main_memory_nid = new_input(OP_STATE, SID_MEMORY_STATE, "zeroed-main-memory", "zeroed main memory");

  if (ISBYTEMEMORY)
    zeroed_main_memory_nid = new_binary(OP_INIT, SID_MEMORY_STATE,
      state_main_memory_nid, NID_BYTE_0, "zeroing memory");
  else
    zeroed_main_memory_nid = new_binary(OP_INIT, SID_MEMORY_STATE,
      state_main_memory_nid, NID_MACHINE_WORD_0, "zeroing memory");

  if (SYNTHESIZE == 0) {
    number_of_hex_digits = round_up(MEMORY_ADDRESS_SPACE, 4) / 4;

    initial_data_segment_nid = state_main_memory_nid;
    initial_heap_segment_nid = state_main_memory_nid;

    initial_main_memory_nid = state_main_memory_nid;

    REUSE_LINES = 1; // TODO: turn off via console argument

    vaddr = data_start;

    while (vaddr < VIRTUALMEMORYSIZE * GIGABYTE - WORDSIZE) {
      if (vaddr == data_start + data_size) {
        initial_data_segment_nid = initial_main_memory_nid;

        vaddr = heap_start;
      }

      if (vaddr == heap_start + heap_size) {
        initial_heap_segment_nid = initial_data_segment_nid;

        vaddr = stack_start;
      }

      if (is_virtual_address_mapped(get_pt(current_context), vaddr)) {
        // memory allocated but not yet mapped is assumed to be zeroed
        data = load_virtual_memory(get_pt(current_context), vaddr);

        if (data != 0) {
          // skipping zero as initial value
          data_nid = new_constant(OP_CONSTH, SID_MACHINE_WORD,
            data,
            0,
            format_comment("data 0x%lX", data));

          if (ISBYTEMEMORY) {
            vaddr_nid = new_constant(OP_CONSTH, SID_MACHINE_WORD,
              vaddr,
              number_of_hex_digits,
              format_comment("vaddr 0x%lX", vaddr));
            initial_main_memory_nid = store_machine_word(vaddr_nid, data_nid, initial_main_memory_nid);
          } else {
            laddr_nid = new_constant(OP_CONSTH, SID_MEMORY_ADDRESS,
              vaddr / WORDSIZE,
              number_of_hex_digits,
              format_comment("vaddr 0x%lX", vaddr));
            initial_main_memory_nid = new_ternary(OP_WRITE, SID_MEMORY_STATE,
              initial_main_memory_nid,
              laddr_nid,
              data_nid,
              "load data");
          }
        }
      }

      vaddr = vaddr + WORDSIZE;
    }

    REUSE_LINES = 1;

    if (initial_main_memory_nid != state_main_memory_nid) {
      state_main_memory_nid = new_input(OP_STATE, SID_MEMORY_STATE,
        "loaded-main-memory", "loaded main memory");

      init_main_memory_nid = new_binary(OP_INIT, SID_MEMORY_STATE,
        state_main_memory_nid, initial_main_memory_nid, "loaded data");
    } else
      init_main_memory_nid = zeroed_main_memory_nid;
  }
}

void print_memory_state() {
  print_break("\n; zeroed main memory\n\n");

  print_line(zeroed_main_memory_nid);

  if (SYNTHESIZE == 0)
    if (initial_main_memory_nid != state_main_memory_nid) {
      // assert: data_size > 0 and non-zero data in data segment

      if (ISBYTEMEMORY)
        // only estimating number of lines needed to store one byte
        print_aligned_break("\n; loaded data segment\n\n",
          log_ten((data_size + heap_size + stack_size) * 5) + 1);
      else
        print_aligned_break("\n; loaded data segment\n\n",
          log_ten((data_size + heap_size + stack_size) / WORDSIZE * 3 + 1) + 1);

      print_line(initial_data_segment_nid);

      if (initial_heap_segment_nid != initial_data_segment_nid) {
        print_break("\n; loaded heap segment\n\n");

        print_line(initial_heap_segment_nid);
      }

      if (initial_main_memory_nid != initial_heap_segment_nid) {
        print_break("\n; loaded stack segment\n\n");

        print_line(initial_main_memory_nid);
      }

      print_break("\n; loaded main memory\n\n");

      print_line(init_main_memory_nid);
    }
}

uint64_t* is_address_in_segment(uint64_t* vaddr_nid, uint64_t* start_nid, uint64_t* end_nid) {
  return new_binary_boolean(OP_AND,
    new_binary_boolean(OP_UGTE,
      vaddr_nid,
      start_nid,
      "vaddr >= start of segment?"),
    new_binary_boolean(OP_ULT,
      vaddr_nid,
      end_nid,
      "vaddr < end of segment?"),
    "vaddr in segment?");
}

uint64_t* is_address_in_code_segment(uint64_t* vaddr_nid) {
  return is_address_in_segment(vaddr_nid, NID_CODE_START, NID_CODE_END);
}

uint64_t* is_address_in_data_segment(uint64_t* vaddr_nid) {
  return is_address_in_segment(vaddr_nid, NID_DATA_START, NID_DATA_END);
}

uint64_t* is_address_in_heap_segment(uint64_t* vaddr_nid) {
  return is_address_in_segment(vaddr_nid, NID_HEAP_START, NID_HEAP_END);
}

uint64_t* is_address_in_stack_segment(uint64_t* vaddr_nid) {
  if (IS64BITTARGET)
    return is_address_in_segment(vaddr_nid, NID_STACK_START, NID_STACK_END);
  else
    // checking end of stack segment is unnecessary since it wraps around to zero
    return new_binary_boolean(OP_UGTE, vaddr_nid, NID_STACK_START, "vaddr >= start of stack segment?");
}

uint64_t* is_address_in_main_memory(uint64_t* vaddr_nid) {
  return new_binary_boolean(OP_OR,
    is_address_in_data_segment(vaddr_nid),
    new_binary_boolean(OP_OR,
      is_address_in_heap_segment(vaddr_nid),
      is_address_in_stack_segment(vaddr_nid),
      "vaddr in heap or stack segment?"),
    "vaddr in data, heap, or stack segment?");
}

uint64_t* is_range_in_segment(uint64_t* vaddr_nid, uint64_t* range_nid, uint64_t* start_nid, uint64_t* end_nid) {
  return new_binary_boolean(OP_AND,
    is_address_in_segment(vaddr_nid, start_nid, end_nid),
    new_binary_boolean(OP_ULTE,
      range_nid,
      new_binary(OP_SUB, SID_MACHINE_WORD,
        end_nid,
        vaddr_nid,
        "end of segment - vaddr"),
      "range <= end of segment - vaddr? (no overflow if vaddr < end of segment)"),
    "all vaddr in range in segment");
}

uint64_t* is_range_in_code_segment(uint64_t* vaddr_nid, uint64_t* range_nid) {
  return is_range_in_segment(vaddr_nid, range_nid, NID_CODE_START, NID_CODE_END);
}

uint64_t* is_range_in_data_segment(uint64_t* vaddr_nid, uint64_t* range_nid) {
  return is_range_in_segment(vaddr_nid, range_nid, NID_DATA_START, NID_DATA_END);
}

uint64_t* is_range_in_heap_segment(uint64_t* vaddr_nid, uint64_t* range_nid) {
  return is_range_in_segment(vaddr_nid, range_nid, NID_HEAP_START, NID_HEAP_END);
}

uint64_t* is_range_in_stack_segment(uint64_t* vaddr_nid, uint64_t* range_nid) {
  if (IS64BITTARGET)
    return is_range_in_segment(vaddr_nid, range_nid, NID_STACK_START, NID_STACK_END);
  else
    return new_binary_boolean(OP_AND,
      is_address_in_stack_segment(vaddr_nid),
      new_binary_boolean(OP_ULTE,
        range_nid,
        new_unary(OP_NEG, SID_MACHINE_WORD,
          vaddr_nid,
          "-vaddr"),
        "range <= -vaddr?"),
      "all vaddr in range in segment");
}

uint64_t* is_range_in_main_memory(uint64_t* vaddr_nid, uint64_t* range_nid) {
  return new_binary_boolean(OP_OR,
    is_range_in_data_segment(vaddr_nid, range_nid),
    new_binary_boolean(OP_OR,
      is_range_in_heap_segment(vaddr_nid, range_nid),
      is_range_in_stack_segment(vaddr_nid, range_nid),
      "all vaddr in range in heap or stack segment?"),
    "all vaddr in range in data, heap, or stack segment?");
}

uint64_t* vaddr_to_code_segment_laddr(uint64_t* vaddr_nid) {
  if (code_start > 0)
    vaddr_nid = new_binary(OP_SUB, SID_MACHINE_WORD, vaddr_nid, NID_CODE_START, "offset code segment start");

  return new_slice(SID_CODE_ADDRESS, vaddr_nid,
    CODE_ADDRESS_SPACE + 1,
    2,
    format_comment("map virtual address to %lu-bit linear address", CODE_ADDRESS_SPACE));
}

uint64_t* vaddr_to_32_bit_laddr(uint64_t* vaddr_nid) {
  return new_slice(SID_MEMORY_ADDRESS, vaddr_nid, 31, 0, "map virtual address to 32-bit linear address");
}

uint64_t* vaddr_to_29_bit_laddr(uint64_t* vaddr_nid) {
  return new_slice(SID_MEMORY_ADDRESS, vaddr_nid, 31, 3, "map virtual address to 29-bit linear address");
}

uint64_t* vaddr_to_30_bit_laddr(uint64_t* vaddr_nid) {
  return new_slice(SID_MEMORY_ADDRESS, vaddr_nid, 31, 2, "map virtual address to 30-bit linear address");
}

uint64_t* vaddr_to_laddr(uint64_t* vaddr_nid) {
  if (ISBYTEMEMORY)
    return vaddr_to_32_bit_laddr(vaddr_nid);
  else if (IS64BITTARGET)
    return vaddr_to_29_bit_laddr(vaddr_nid);
  else
    return vaddr_to_30_bit_laddr(vaddr_nid);
}

uint64_t* load_byte_from_bytes(uint64_t* vaddr_nid, uint64_t* memory_nid) {
  return new_binary(OP_READ, SID_MEMORY_WORD,
    memory_nid,
    vaddr_to_laddr(vaddr_nid),
    "load byte from memory at vaddr");
}

uint64_t* store_byte_in_bytes(uint64_t* vaddr_nid, uint64_t* byte_nid, uint64_t* memory_nid) {
  return new_ternary(OP_WRITE, SID_MEMORY_STATE,
    memory_nid,
    vaddr_to_laddr(vaddr_nid),
    byte_nid,
    "store byte in memory at vaddr");
}

uint64_t* get_vaddr_alignment(uint64_t* vaddr_nid, uint64_t* alignment_nid) {
  return new_binary(OP_AND, SID_MACHINE_WORD, vaddr_nid, alignment_nid, "mask alignment bits");
}

uint64_t* shift_by_alignment_in_bits(uint64_t* vaddr_nid, uint64_t* alignment_nid) {
  return new_binary(OP_SLL, SID_MACHINE_WORD,
    get_vaddr_alignment(vaddr_nid, alignment_nid),
    NID_BYTE_SIZE_IN_BASE_BITS,
    "multiply by 8 bits");
}

uint64_t* shift_from_vaddr(uint64_t* vaddr_nid, uint64_t* alignment_nid, uint64_t* value_nid) {
  return new_binary(OP_SRL, SID_MACHINE_WORD,
    value_nid,
    shift_by_alignment_in_bits(vaddr_nid, alignment_nid),
    "shift right from vaddr");
}

uint64_t* shift_to_vaddr(uint64_t* vaddr_nid, uint64_t* alignment_nid, uint64_t* value_nid) {
  return new_binary(OP_SLL, SID_MACHINE_WORD,
    value_nid,
    shift_by_alignment_in_bits(vaddr_nid, alignment_nid),
    "shift left to vaddr");
}

uint64_t* slice_byte_from_machine_word(uint64_t* word_nid) {
  return new_slice(SID_BYTE, word_nid, 7, 0, "slice least-significant byte");
}

uint64_t* extend_byte_to_machine_word(char* op, uint64_t* byte_nid) {
  return new_ext(op, SID_MACHINE_WORD,
    byte_nid,
    WORDSIZEINBITS - 8,
    "extension of byte to machine word");
}

uint64_t* insert_value_into_machine_word(uint64_t* word_nid,
  uint64_t* vaddr_nid, uint64_t* value_mask_nid, uint64_t* value_nid) {

  if (IS64BITTARGET == 0)
    if (value_mask_nid == NID_SINGLE_WORD_MASK)
      return value_nid;

  return new_binary(OP_OR, SID_MACHINE_WORD,
    new_binary(OP_AND, SID_MACHINE_WORD,
      word_nid,
      new_unary(OP_NOT, SID_MACHINE_WORD,
        shift_to_vaddr(vaddr_nid,
          NID_MACHINE_WORD_SIZE_MASK,
          value_mask_nid),
        "bitwise-not value mask"),
      "reset bits at value location"),
    shift_to_vaddr(vaddr_nid,
      NID_MACHINE_WORD_SIZE_MASK,
      value_nid),
    "insert value at value location");
}

uint64_t* load_byte_from_machine_word(uint64_t* vaddr_nid, uint64_t* memory_nid) {
  return slice_byte_from_machine_word(
    shift_from_vaddr(vaddr_nid,
      NID_MACHINE_WORD_SIZE_MASK,
      load_machine_word(vaddr_nid, memory_nid)));
}

uint64_t* store_byte_in_machine_word(uint64_t* vaddr_nid, uint64_t* byte_nid, uint64_t* memory_nid) {
  return store_machine_word(vaddr_nid,
    insert_value_into_machine_word(
      load_machine_word(vaddr_nid, memory_nid),
      vaddr_nid,
      NID_BYTE_MASK,
      extend_byte_to_machine_word(OP_UEXT, byte_nid)),
    memory_nid);
}

uint64_t* load_byte(uint64_t* vaddr_nid, uint64_t* memory_nid) {
  if (ISBYTEMEMORY)
    return load_byte_from_bytes(vaddr_nid, memory_nid);
  else
    return load_byte_from_machine_word(vaddr_nid, memory_nid);
}

uint64_t* store_byte(uint64_t* vaddr_nid, uint64_t* byte_nid, uint64_t* memory_nid) {
  if (ISBYTEMEMORY)
    return store_byte_in_bytes(vaddr_nid, byte_nid, memory_nid);
  else
    return store_byte_in_machine_word(vaddr_nid, byte_nid, memory_nid);
}

uint64_t* slice_lower_byte_from_half_word(uint64_t* word_nid) {
  return new_slice(SID_BYTE, word_nid, 7, 0, "slice lower byte from half word");
}

uint64_t* slice_upper_byte_from_half_word(uint64_t* word_nid) {
  return new_slice(SID_BYTE, word_nid, 15, 8, "slice upper byte from half word");
}

uint64_t* load_half_word_from_bytes(uint64_t* vaddr_nid, uint64_t* memory_nid) {
  return new_binary(OP_CONCAT, SID_HALF_WORD,
    load_byte(new_unary(OP_INC, SID_MACHINE_WORD, vaddr_nid, "vaddr + 1"), memory_nid),
    load_byte(vaddr_nid, memory_nid),
    "load half word from bytes");
}

uint64_t* store_half_word_in_bytes(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid) {
  return store_byte(vaddr_nid,
    slice_lower_byte_from_half_word(word_nid),
    store_byte(new_unary(OP_INC, SID_MACHINE_WORD, vaddr_nid, "vaddr + 1"),
      slice_upper_byte_from_half_word(word_nid),
      memory_nid));
}

uint64_t* is_contained_in_machine_word(uint64_t* vaddr_nid, uint64_t* relative_size_nid) {
  return new_binary_boolean(OP_ULTE,
    get_vaddr_alignment(vaddr_nid, NID_MACHINE_WORD_SIZE_MASK),
    relative_size_nid,
    "is contained in machine word");
}

uint64_t* slice_half_word_from_machine_word(uint64_t* word_nid) {
  return new_slice(SID_HALF_WORD, word_nid, 15, 0, "slice least-significant half word");
}

uint64_t* extend_half_word_to_machine_word(char* op, uint64_t* word_nid) {
  return new_ext(op, SID_MACHINE_WORD,
    word_nid,
    WORDSIZEINBITS - 16,
    "extension of half word to machine word");
}

uint64_t* load_half_word_from_machine_words(uint64_t* vaddr_nid, uint64_t* memory_nid) {
  return new_ternary(OP_ITE, SID_HALF_WORD,
    is_contained_in_machine_word(vaddr_nid,
      NID_MACHINE_WORD_SIZE_MINUS_HALF_WORD_SIZE),
    slice_half_word_from_machine_word(shift_from_vaddr(
      vaddr_nid,
      NID_MACHINE_WORD_SIZE_MASK,
      load_machine_word(vaddr_nid, memory_nid))),
    load_half_word_from_bytes(vaddr_nid, memory_nid),
    "load half word from machine words");
}

uint64_t* store_half_word_in_machine_words(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid) {
  return new_ternary(OP_ITE, SID_MEMORY_STATE,
    is_contained_in_machine_word(vaddr_nid,
      NID_MACHINE_WORD_SIZE_MINUS_HALF_WORD_SIZE),
    store_machine_word(vaddr_nid,
      insert_value_into_machine_word(
        load_machine_word(vaddr_nid, memory_nid),
        vaddr_nid,
        NID_HALF_WORD_MASK,
        extend_half_word_to_machine_word(OP_UEXT, word_nid)),
      memory_nid),
    store_half_word_in_bytes(vaddr_nid,
      word_nid,
      memory_nid),
    "store half word in machine words");
}

uint64_t* load_half_word(uint64_t* vaddr_nid, uint64_t* memory_nid) {
  if (ISBYTEMEMORY)
    return load_half_word_from_bytes(vaddr_nid, memory_nid);
  else
    return load_half_word_from_machine_words(vaddr_nid, memory_nid);
}

uint64_t* store_half_word(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid) {
  if (ISBYTEMEMORY)
    return store_half_word_in_bytes(vaddr_nid, word_nid, memory_nid);
  else
    return store_half_word_in_machine_words(vaddr_nid, word_nid, memory_nid);
}

uint64_t* slice_lower_half_word_from_single_word(uint64_t* word_nid) {
  return new_slice(SID_HALF_WORD, word_nid, 15, 0, "slice lower half word from single word");
}

uint64_t* slice_upper_half_word_from_single_word(uint64_t* word_nid) {
  return new_slice(SID_HALF_WORD, word_nid, 31, 16, "slice upper half word from single word");
}

uint64_t* load_single_word_from_half_words(uint64_t* vaddr_nid, uint64_t* memory_nid) {
  return new_binary(OP_CONCAT, SID_SINGLE_WORD,
    load_half_word(new_binary(OP_ADD, SID_MACHINE_WORD,
      vaddr_nid,
      NID_MACHINE_WORD_2,
      "vaddr + 2"),
      memory_nid),
    load_half_word(vaddr_nid, memory_nid),
    "load single word from half words");
}

uint64_t* store_single_word_in_half_words(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid) {
  return store_half_word(vaddr_nid,
    slice_lower_half_word_from_single_word(word_nid),
    store_half_word(new_binary(OP_ADD, SID_MACHINE_WORD,
      vaddr_nid,
      NID_MACHINE_WORD_2,
      "vaddr + 2"),
      slice_upper_half_word_from_single_word(word_nid),
      memory_nid));
}

uint64_t* slice_single_word_from_machine_word(uint64_t* word_nid) {
  if (IS64BITTARGET)
    return new_slice(SID_SINGLE_WORD, word_nid, 31, 0, "slice least-significant single word");
  else
    return word_nid;
}

uint64_t* extend_single_word_to_machine_word(char* op, uint64_t* word_nid) {
  if (IS64BITTARGET)
    return new_ext(op, SID_MACHINE_WORD,
      word_nid,
      WORDSIZEINBITS - 32,
      "extension of single word to machine word");
  else
    return word_nid;
}

uint64_t* load_single_word_from_machine_words(uint64_t* vaddr_nid, uint64_t* memory_nid) {
  return new_ternary(OP_ITE, SID_SINGLE_WORD,
    is_contained_in_machine_word(vaddr_nid,
      NID_MACHINE_WORD_SIZE_MINUS_SINGLE_WORD_SIZE),
    slice_single_word_from_machine_word(shift_from_vaddr(
      vaddr_nid,
      NID_MACHINE_WORD_SIZE_MASK,
      load_machine_word(vaddr_nid, memory_nid))),
    load_single_word_from_half_words(vaddr_nid, memory_nid),
    "load single word from machine words");
}

uint64_t* store_single_word_in_machine_words(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid) {
  return new_ternary(OP_ITE, SID_MEMORY_STATE,
    is_contained_in_machine_word(vaddr_nid,
      NID_MACHINE_WORD_SIZE_MINUS_SINGLE_WORD_SIZE),
    store_machine_word(vaddr_nid,
      insert_value_into_machine_word(
        load_machine_word(vaddr_nid, memory_nid),
        vaddr_nid,
        NID_SINGLE_WORD_MASK,
        extend_single_word_to_machine_word(OP_UEXT, word_nid)),
      memory_nid),
    store_single_word_in_half_words(vaddr_nid,
      word_nid,
      memory_nid),
    "store single word in machine words");
}

uint64_t* load_single_word(uint64_t* vaddr_nid, uint64_t* memory_nid) {
  if (ISBYTEMEMORY)
    return load_single_word_from_half_words(vaddr_nid, memory_nid);
  else
    return load_single_word_from_machine_words(vaddr_nid, memory_nid);
}

uint64_t* store_single_word(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid) {
  if (ISBYTEMEMORY)
    return store_single_word_in_half_words(vaddr_nid, word_nid, memory_nid);
  else
    return store_single_word_in_machine_words(vaddr_nid, word_nid, memory_nid);
}

uint64_t* slice_lower_single_word_from_double_word(uint64_t* word_nid) {
  return new_slice(SID_SINGLE_WORD, word_nid, 31, 0, "slice lower single word from double word");
}

uint64_t* slice_upper_single_word_from_double_word(uint64_t* word_nid) {
  return new_slice(SID_SINGLE_WORD, word_nid, 63, 32, "slice upper single word from double word");
}

uint64_t* load_double_word_from_single_words(uint64_t* vaddr_nid, uint64_t* memory_nid) {
  return new_binary(OP_CONCAT, SID_DOUBLE_WORD,
    load_single_word(new_binary(OP_ADD, SID_MACHINE_WORD,
        vaddr_nid,
        NID_MACHINE_WORD_4,
        "vaddr + 4"),
      memory_nid),
    load_single_word(vaddr_nid, memory_nid),
    "load double word from single words");
}

uint64_t* store_double_word_in_single_words(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid) {
  return store_single_word(vaddr_nid,
    slice_lower_single_word_from_double_word(word_nid),
    store_single_word(new_binary(OP_ADD, SID_MACHINE_WORD,
      vaddr_nid,
      NID_MACHINE_WORD_4,
      "vaddr + 4"),
      slice_upper_single_word_from_double_word(word_nid),
      memory_nid));
}

uint64_t* load_double_word_from_machine_words(uint64_t* vaddr_nid, uint64_t* memory_nid) {
  return new_ternary(OP_ITE, SID_DOUBLE_WORD,
    is_contained_in_machine_word(vaddr_nid, NID_MACHINE_WORD_0),
    load_machine_word(vaddr_nid, memory_nid),
    load_double_word_from_single_words(vaddr_nid, memory_nid),
    "load double word from machine words");
}

uint64_t* store_double_word_in_machine_words(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid) {
  return new_ternary(OP_ITE, SID_MEMORY_STATE,
    is_contained_in_machine_word(vaddr_nid, NID_MACHINE_WORD_0),
    store_machine_word(vaddr_nid, word_nid, memory_nid),
    store_double_word_in_single_words(vaddr_nid, word_nid, memory_nid),
    "store double word in machine words");
}

uint64_t* load_double_word(uint64_t* vaddr_nid, uint64_t* memory_nid) {
  if (IS64BITTARGET)
    if (ISBYTEMEMORY)
      return load_double_word_from_single_words(vaddr_nid, memory_nid);
    else
      return load_double_word_from_machine_words(vaddr_nid, memory_nid);
  else
    return NID_MACHINE_WORD_0;
}

uint64_t* store_double_word(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid) {
  if (IS64BITTARGET)
    if (ISBYTEMEMORY)
      return store_double_word_in_single_words(vaddr_nid, word_nid, memory_nid);
    else
      return store_double_word_in_machine_words(vaddr_nid, word_nid, memory_nid);
  else
    return memory_nid;
}

uint64_t* load_machine_word_from_word_memory(uint64_t* vaddr_nid, uint64_t* memory_nid) {
  return new_binary(OP_READ, SID_MEMORY_WORD,
    memory_nid,
    vaddr_to_laddr(vaddr_nid),
    "load machine word from memory at vaddr");
}

uint64_t* store_machine_word_in_word_memory(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid) {
  return new_ternary(OP_WRITE, SID_MEMORY_STATE,
    memory_nid,
    vaddr_to_laddr(vaddr_nid),
    word_nid,
    "store machine word in memory at vaddr");
}

uint64_t* load_machine_word(uint64_t* vaddr_nid, uint64_t* memory_nid) {
  if (ISBYTEMEMORY)
    if (IS64BITTARGET)
      return load_double_word_from_single_words(vaddr_nid, memory_nid);
    else
      return load_single_word_from_half_words(vaddr_nid, memory_nid);
  else
    return load_machine_word_from_word_memory(vaddr_nid, memory_nid);
}

uint64_t* store_machine_word(uint64_t* vaddr_nid, uint64_t* word_nid, uint64_t* memory_nid) {
  if (ISBYTEMEMORY)
    if (IS64BITTARGET)
      return store_double_word_in_single_words(vaddr_nid, word_nid, memory_nid);
    else
      return store_single_word_in_half_words(vaddr_nid, word_nid, memory_nid);
  else
    return store_machine_word_in_word_memory(vaddr_nid, word_nid, memory_nid);
}

uint64_t* fetch_instruction(uint64_t* pc_nid) {
  return new_binary(OP_READ, SID_INSTRUCTION_WORD,
    state_code_segment_nid,
    vaddr_to_code_segment_laddr(pc_nid),
    "fetch instruction");
}

// -----------------------------------------------------------------
// ------------------------- INSTRUCTIONS --------------------------
// -----------------------------------------------------------------

uint64_t* get_instruction_opcode(uint64_t* ir_nid) {
  return new_slice(SID_OPCODE, ir_nid, 6, 0, "get opcode");
}

uint64_t* get_instruction_funct3(uint64_t* ir_nid) {
  return new_slice(SID_FUNCT3, ir_nid, 14, 12, "get funct3");
}

uint64_t* get_instruction_funct7(uint64_t* ir_nid) {
  return new_slice(SID_FUNCT7, ir_nid, 31, 25, "get funct7");
}

uint64_t* get_instruction_funct6(uint64_t* ir_nid) {
  return new_slice(SID_FUNCT6, ir_nid, 31, 26, "get funct6");
}

uint64_t* get_instruction_rd(uint64_t* ir_nid) {
  return new_slice(SID_REGISTER_ADDRESS, ir_nid, 11, 7, "get rd");
}

uint64_t* get_instruction_rs1(uint64_t* ir_nid) {
  return new_slice(SID_REGISTER_ADDRESS, ir_nid, 19, 15, "get rs1");
}

uint64_t* get_instruction_rs2(uint64_t* ir_nid) {
  return new_slice(SID_REGISTER_ADDRESS, ir_nid, 24, 20, "get rs2");
}

uint64_t* sign_extend_IS_immediate(uint64_t* imm_nid) {
  return new_ext(OP_SEXT, SID_MACHINE_WORD, imm_nid, WORDSIZEINBITS - 12, "sign-extend immediate");
}

uint64_t* get_instruction_I_immediate(uint64_t* ir_nid) {
  return sign_extend_IS_immediate(
    new_slice(SID_12_BIT_IMM, ir_nid, 31, 20, "get I-immediate"));
}

uint64_t* get_instruction_I_immediate_32(uint64_t* ir_nid) {
  return new_ext(OP_SEXT, SID_SINGLE_WORD,
    new_slice(SID_12_BIT_IMM, ir_nid, 31, 20, "get I-immediate"),
    SINGLEWORDSIZEINBITS - 12,
    "sign-extend immediate");
}

uint64_t* get_instruction_shamt(uint64_t* ir_nid) {
  if (IS64BITTARGET)
    return new_ext(OP_UEXT, SID_MACHINE_WORD,
      new_slice(SID_6_BIT_IMM, ir_nid, 25, 20, "get 6-bit shamt"),
      WORDSIZEINBITS - 6,
      "unsigned-extend 6-bit shamt");
  else
    return new_ext(OP_UEXT, SID_MACHINE_WORD,
      new_slice(SID_5_BIT_IMM, ir_nid, 24, 20, "get 5-bit shamt"),
      WORDSIZEINBITS - 5,
      "unsigned-extend 5-bit shamt");
}

uint64_t* get_instruction_shamt_32(uint64_t* ir_nid) {
  return new_ext(OP_UEXT, SID_SINGLE_WORD,
    new_slice(SID_5_BIT_IMM, ir_nid, 24, 20, "get 5-bit shamt"),
    SINGLEWORDSIZEINBITS - 5,
    "unsigned-extend 5-bit shamt");
}

uint64_t* get_instruction_S_immediate(uint64_t* ir_nid) {
  return sign_extend_IS_immediate(
    new_binary(OP_CONCAT, SID_12_BIT_IMM,
      get_instruction_funct7(ir_nid),
      get_instruction_rd(ir_nid),
      "get S-immediate"));
}

uint64_t* sign_extend_SB_immediate(uint64_t* imm_nid) {
  return new_ext(OP_SEXT, SID_MACHINE_WORD, imm_nid, WORDSIZEINBITS - 13, "sign-extend");
}

uint64_t* get_instruction_SB_immediate(uint64_t* ir_nid) {
  return sign_extend_SB_immediate(
    new_binary(OP_CONCAT, SID_13_BIT_IMM,
      new_slice(SID_1_BIT_IMM, ir_nid, 31, 31, "get SB-immediate[12]"),
      new_binary(OP_CONCAT, SID_12_BIT_IMM,
        new_slice(SID_1_BIT_IMM, ir_nid, 7, 7, "get SB-immediate[11]"),
        new_binary(OP_CONCAT, SID_11_BIT_IMM,
          new_slice(SID_6_BIT_IMM, ir_nid, 30, 25, "get SB-immediate[10:5]"),
          new_binary(OP_CONCAT, SID_5_BIT_IMM,
            new_slice(SID_4_BIT_IMM, ir_nid, 11, 8, "get SB-immediate[4:1]"),
            NID_1_BIT_IMM_0,
            "get SB-immediate[4:0]"),
          "get SB-immediate[10:0]"),
        "get SB-immediate[11:0]"),
      "get SB-immediate[12:0]"));
}

uint64_t* sign_extend_U_immediate(uint64_t* imm_nid) {
  // redundant with extend_single_word_to_machine_word
  if (IS64BITTARGET)
    return new_ext(OP_SEXT, SID_MACHINE_WORD, imm_nid, WORDSIZEINBITS - 32, "sign-extend");
  else
    return imm_nid;
}

uint64_t* get_instruction_U_immediate(uint64_t* ir_nid) {
  return sign_extend_U_immediate(
    new_binary(OP_CONCAT, SID_32_BIT_IMM,
      new_slice(SID_20_BIT_IMM, ir_nid, 31, 12, "get U-immediate[31:12]"),
      NID_12_BIT_IMM_0,
      "get UJ-immediate[31:0]"));
}

uint64_t* sign_extend_UJ_immediate(uint64_t* imm_nid) {
  return new_ext(OP_SEXT, SID_MACHINE_WORD, imm_nid, WORDSIZEINBITS - 21, "sign-extend");
}

uint64_t* get_instruction_UJ_immediate(uint64_t* ir_nid) {
  return sign_extend_UJ_immediate(
    new_binary(OP_CONCAT, SID_21_BIT_IMM,
      new_slice(SID_1_BIT_IMM, ir_nid, 31, 31, "get UJ-immediate[20]"),
      new_binary(OP_CONCAT, SID_20_BIT_IMM,
        new_slice(SID_8_BIT_IMM, ir_nid, 19, 12, "get UJ-immediate[19:12]"),
        new_binary(OP_CONCAT, SID_12_BIT_IMM,
          new_slice(SID_1_BIT_IMM, ir_nid, 20, 20, "get UJ-immediate[11]"),
          new_binary(OP_CONCAT, SID_11_BIT_IMM,
            new_slice(SID_10_BIT_IMM, ir_nid, 30, 21, "get UJ-immediate[10:1]"),
            NID_1_BIT_IMM_0,
            "get UJ-immediate[10:0]"),
          "get UJ-immediate[11:0]"),
        "get UJ-immediate[19:0]"),
      "get UJ-immediate[20:0]"));
}

uint64_t* decode_opcode(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* opcode_nid, char* opcode_comment,
  uint64_t* execute_nid, char* execute_comment,
  uint64_t* other_opcode_nid) {
  return new_ternary(OP_ITE, sid,
    new_binary_boolean(OP_EQ,
      get_instruction_opcode(ir_nid),
      opcode_nid,
      format_comment("opcode == %s", (uint64_t) opcode_comment)),
    execute_nid,
    other_opcode_nid,
    execute_comment);
}

uint64_t* decode_funct3(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* funct3_nid, char* funct3_comment,
  uint64_t* execute_nid, char* execute_comment,
  uint64_t* other_funct3_nid) {
  return new_ternary(OP_ITE, sid,
    new_binary_boolean(OP_EQ,
      get_instruction_funct3(ir_nid),
      funct3_nid,
      format_comment("funct3 == %s", (uint64_t) funct3_comment)),
    execute_nid,
    other_funct3_nid,
    execute_comment);
}

uint64_t* decode_funct3_conditional(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* funct3_nid, char* funct3_comment,
  uint64_t* evaluate_nid, uint64_t* execute_nid, char* execute_comment,
  uint64_t* other_funct3_nid) {
  return new_ternary(OP_ITE, sid,
    new_binary_boolean(OP_AND,
      new_binary_boolean(OP_EQ,
        get_instruction_funct3(ir_nid),
        funct3_nid,
        format_comment("funct3 == %s", (uint64_t) funct3_comment)),
      evaluate_nid,
      "evaluate branch condition if funct3 matches"),
    execute_nid,
    other_funct3_nid,
    execute_comment);
}

uint64_t* decode_funct7(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* funct7_nid, char* funct7_comment,
  uint64_t* execute_nid, char* execute_comment,
  uint64_t* other_funct7_nid) {
  return new_ternary(OP_ITE, sid,
    new_binary_boolean(OP_EQ,
      get_instruction_funct7(ir_nid),
      funct7_nid,
      format_comment("funct7 == %s", (uint64_t) funct7_comment)),
    execute_nid,
    other_funct7_nid,
    execute_comment);
}

uint64_t* decode_lui(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* lui_nid, char* comment,
  uint64_t* other_opcode_nid) {
  return decode_opcode(sid, ir_nid,
    NID_OP_LUI, "LUI?",
    lui_nid, format_comment("lui %s", (uint64_t) comment),
    other_opcode_nid);
}

uint64_t* decode_auipc(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* auipc_nid, char* comment,
  uint64_t* other_opcode_nid) {
  return decode_opcode(sid, ir_nid,
    NID_OP_AUIPC, "AUIPC?",
    auipc_nid, format_comment("auipc %s", (uint64_t) comment),
    other_opcode_nid);
}

uint64_t* decode_funct7_6(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* funct_nid, char* funct_comment,
  uint64_t* execute_nid, char* execute_comment,
  uint64_t* other_funct_nid) {
  if (IS64BITTARGET)
    return new_ternary(OP_ITE, sid,
      new_binary_boolean(OP_EQ,
        get_instruction_funct6(ir_nid),
        funct_nid,
        format_comment("funct6 == %s", (uint64_t) funct_comment)),
      execute_nid,
      other_funct_nid,
      execute_comment);
  else
    return new_ternary(OP_ITE, sid,
      new_binary_boolean(OP_EQ,
        get_instruction_funct7(ir_nid),
        funct_nid,
        format_comment("funct7 == %s", (uint64_t) funct_comment)),
      execute_nid,
      other_funct_nid,
      execute_comment);
}

uint64_t* decode_shift_w(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* funct7_sll_srl_nid, uint64_t* slliw_nid, uint64_t* srliw_nid,
  uint64_t* funct7_sra_nid, uint64_t* sraiw_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* no_funct7_nid) {
  return decode_funct7(sid, ir_nid,
    funct7_sll_srl_nid, "SLLIW or SRLIW?",
    decode_funct3(sid, ir_nid,
      NID_F3_SLL, "SLLIW?",
      slliw_nid, format_comment("slliw %s", (uint64_t) comment),
      decode_funct3(sid, ir_nid,
        NID_F3_SRL, "SRLIW?",
        srliw_nid, format_comment("srliw %s", (uint64_t) comment),
        no_funct3_nid)),
    format_comment("slliw or srliw %s", (uint64_t) comment),
    decode_funct7(sid, ir_nid,
      funct7_sra_nid, "SRAIW?",
      decode_funct3(sid, ir_nid,
        NID_F3_SRA, "SRAIW?",
        sraiw_nid, format_comment("sraiw %s", (uint64_t) comment),
        no_funct3_nid),
      format_comment("sraiw %s", (uint64_t) comment),
      no_funct7_nid));
}

uint64_t* decode_shift_imm(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* funct_sll_srl_nid, uint64_t* slli_nid, uint64_t* srli_nid,
  uint64_t* funct_sra_nid, uint64_t* srai_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* no_funct7_nid) {
  return decode_funct7_6(sid, ir_nid,
    funct_sll_srl_nid, "SLLI or SRLI?",
    decode_funct3(sid, ir_nid,
      NID_F3_SLL, "SLLI?",
      slli_nid, format_comment("slli %s", (uint64_t) comment),
      decode_funct3(sid, ir_nid,
        NID_F3_SRL, "SRLI?",
        srli_nid, format_comment("srli %s", (uint64_t) comment),
        no_funct3_nid)),
    format_comment("slli or srli %s", (uint64_t) comment),
    decode_funct7_6(sid, ir_nid,
      funct_sra_nid, "SRAI?",
      decode_funct3(sid, ir_nid,
        NID_F3_SRA, "SRAI?",
        srai_nid, format_comment("srai %s", (uint64_t) comment),
        no_funct3_nid),
      format_comment("srai %s", (uint64_t) comment),
      no_funct7_nid));
}

uint64_t* decode_illegal_shift_imm(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* slli_nid, uint64_t* srli_nid, uint64_t* srai_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* no_funct7_nid, uint64_t* other_opcode_nid) {
  if (IS64BITTARGET)
    return decode_opcode(sid, ir_nid,
      NID_OP_IMM_32, "IMM-32?",
      decode_shift_w(sid, ir_nid,
        NID_F7_SLL_SRL_ILLEGAL, slli_nid, srli_nid,
        NID_F7_SRA_ILLEGAL, srai_nid, comment,
        no_funct3_nid, no_funct7_nid),
      format_comment("illegal shift imm-32 %s", (uint64_t) comment),
      other_opcode_nid);
  else
    return decode_opcode(sid, ir_nid,
      NID_OP_IMM, "IMM?",
      decode_shift_imm(sid, ir_nid,
        NID_F7_SLL_SRL_ILLEGAL, slli_nid, srli_nid,
        NID_F7_SRA_ILLEGAL, srai_nid, comment,
        no_funct3_nid, no_funct7_nid),
      format_comment("illegal shift imm %s", (uint64_t) comment),
      other_opcode_nid);
}

uint64_t* decode_imm_32(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* addiw_nid, uint64_t* slliw_nid, uint64_t* srliw_nid, uint64_t* sraiw_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* no_funct7_nid, uint64_t* other_opcode_nid) {
  if (IS64BITTARGET)
    return decode_opcode(sid, ir_nid,
      NID_OP_IMM_32, "IMM-32?",
      decode_funct3(sid, ir_nid,
        NID_F3_ADDI, "ADDIW?",
        addiw_nid, format_comment("addiw %s", (uint64_t) comment),
        decode_shift_w(sid, ir_nid,
          NID_F7_ADD_SLT_XOR_OR_AND_SLL_SRL, slliw_nid, srliw_nid,
          NID_F7_SUB_SRA, sraiw_nid, comment,
          no_funct3_nid, no_funct7_nid)),
      format_comment("imm-32 %s", (uint64_t) comment),
      other_opcode_nid);
  else
    return other_opcode_nid;
}

uint64_t* decode_imm(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* addi_nid, uint64_t* slti_nid, uint64_t* sltiu_nid,
  uint64_t* xori_nid, uint64_t* ori_nid, uint64_t* andi_nid,
  uint64_t* slli_nid, uint64_t* srli_nid, uint64_t* srai_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* no_funct7_nid, uint64_t* other_opcode_nid) {
  uint64_t* funct_sll_srl_nid;
  uint64_t* funct_sra_nid;

  if (IS64BITTARGET) {
    funct_sll_srl_nid = NID_F6_SLL_SRL;
    funct_sra_nid     = NID_F6_SRA;
  } else {
    funct_sll_srl_nid = NID_F7_ADD_SLT_XOR_OR_AND_SLL_SRL;
    funct_sra_nid     = NID_F7_SUB_SRA;
  }

  return decode_opcode(sid, ir_nid,
    NID_OP_IMM, "IMM?",
    decode_funct3(sid, ir_nid,
      NID_F3_ADDI, "ADDI?",
      addi_nid, format_comment("addi %s", (uint64_t) comment),
      decode_funct3(sid, ir_nid,
        NID_F3_SLT, "SLTI?",
        slti_nid, format_comment("slti %s", (uint64_t) comment),
        decode_funct3(sid, ir_nid,
          NID_F3_SLTU, "SLTIU?",
          sltiu_nid, format_comment("sltiu %s", (uint64_t) comment),
          decode_funct3(sid, ir_nid,
            NID_F3_XOR, "XORI?",
            xori_nid, format_comment("xori %s", (uint64_t) comment),
            decode_funct3(sid, ir_nid,
              NID_F3_OR, "ORI?",
              ori_nid, format_comment("ori %s", (uint64_t) comment),
              decode_funct3(sid, ir_nid,
                NID_F3_AND, "ANDI?",
                andi_nid, format_comment("andi %s", (uint64_t) comment),
                decode_shift_imm(sid, ir_nid,
                  funct_sll_srl_nid, slli_nid, srli_nid,
                  funct_sra_nid, srai_nid, comment,
                  no_funct3_nid, no_funct7_nid))))))),
    format_comment("imm %s", (uint64_t) comment),
    other_opcode_nid);
}

uint64_t* decode_op(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* add_nid, uint64_t* sub_nid,
  uint64_t* slt_nid, uint64_t* sltu_nid,
  uint64_t* xor_nid, uint64_t* or_nid, uint64_t* and_nid,
  uint64_t* sll_nid, uint64_t* srl_nid, uint64_t* sra_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* RV32M_nid, uint64_t* other_opcode_nid) {
  return decode_opcode(sid, ir_nid,
    NID_OP_OP, "OP?",
    decode_funct7(sid, ir_nid,
      NID_F7_ADD_SLT_XOR_OR_AND_SLL_SRL, "ADD or SLTU?",
      decode_funct3(sid, ir_nid,
        NID_F3_ADD_SUB_MUL, "ADD?",
        add_nid, format_comment("add %s", (uint64_t) comment),
        decode_funct3(sid, ir_nid,
          NID_F3_SLT, "SLT?",
          slt_nid, format_comment("slt %s", (uint64_t) comment),
          decode_funct3(sid, ir_nid,
            NID_F3_SLTU, "SLTU?",
            sltu_nid, format_comment("sltu %s", (uint64_t) comment),
            decode_funct3(sid, ir_nid,
              NID_F3_XOR, "XOR?",
              xor_nid, format_comment("xor %s", (uint64_t) comment),
              decode_funct3(sid, ir_nid,
                NID_F3_OR, "OR?",
                or_nid, format_comment("or %s", (uint64_t) comment),
                decode_funct3(sid, ir_nid,
                  NID_F3_AND, "AND?",
                  and_nid, format_comment("and %s", (uint64_t) comment),
                  decode_funct3(sid, ir_nid,
                    NID_F3_SLL, "SLL?",
                    sll_nid, format_comment("sll %s", (uint64_t) comment),
                    decode_funct3(sid, ir_nid,
                      NID_F3_SRL, "SRL?",
                      srl_nid, format_comment("srl %s", (uint64_t) comment),
                      no_funct3_nid)))))))),
      format_comment("add or slt or sltu or xor or or or and or sll or srl %s", (uint64_t) comment),
      decode_funct7(sid, ir_nid,
        NID_F7_SUB_SRA, "SUB?",
        decode_funct3(sid, ir_nid,
          NID_F3_ADD_SUB_MUL, "SUB?",
          sub_nid, format_comment("sub %s", (uint64_t) comment),
          decode_funct3(sid, ir_nid,
            NID_F3_SRA, "SRA?",
            sra_nid, format_comment("sra %s", (uint64_t) comment),
            no_funct3_nid)),
        format_comment("sub or sra %s", (uint64_t) comment),
        RV32M_nid)),
    format_comment("op %s", (uint64_t) comment),
    other_opcode_nid);
}

uint64_t* decode_RV32M(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* mul_nid, uint64_t* mulh_nid, uint64_t* mulhsu_nid, uint64_t* mulhu_nid,
  uint64_t* div_nid, uint64_t* divu_nid, uint64_t* rem_nid, uint64_t* remu_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* no_funct7_nid) {
  if (RV32M)
    return decode_funct7(sid, ir_nid,
      NID_F7_MUL_DIV_REM, "MUL or DIVU or REMU?",
      decode_funct3(sid, ir_nid,
        NID_F3_ADD_SUB_MUL, "MUL?",
        mul_nid, format_comment("mul %s", (uint64_t) comment),
        decode_funct3(sid, ir_nid,
          NID_F3_MULH, "MULH?",
          mulh_nid, format_comment("mulh %s", (uint64_t) comment),
          decode_funct3(sid, ir_nid,
            NID_F3_MULHSU, "MULHSU?",
            mulhsu_nid, format_comment("mulhsu %s", (uint64_t) comment),
            decode_funct3(sid, ir_nid,
              NID_F3_MULHU, "MULHU?",
              mulhu_nid, format_comment("mulhu %s", (uint64_t) comment),
              decode_funct3(sid, ir_nid,
                NID_F3_DIV, "DIV?",
                div_nid, format_comment("div %s", (uint64_t) comment),
                decode_funct3(sid, ir_nid,
                  NID_F3_DIVU, "DIVU?",
                  divu_nid, format_comment("divu %s", (uint64_t) comment),
                  decode_funct3(sid, ir_nid,
                    NID_F3_REM, "REM?",
                    rem_nid, format_comment("rem %s", (uint64_t) comment),
                    decode_funct3(sid, ir_nid,
                      NID_F3_REMU, "REMU?",
                      remu_nid, format_comment("remu %s", (uint64_t) comment),
                      no_funct3_nid)))))))),
      format_comment("mul or mulh or mulhsu or mulhu or div or divu or rem or remu %s", (uint64_t) comment),
      no_funct7_nid);
  else
    return no_funct7_nid;
}

uint64_t* decode_load(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* ld_nid,
  uint64_t* lw_nid, uint64_t* lwu_nid,
  uint64_t* lh_nid, uint64_t* lhu_nid,
  uint64_t* lb_nid, uint64_t* lbu_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* other_opcode_nid) {
  return decode_opcode(sid, ir_nid,
    NID_OP_LOAD, "LOAD?",
    decode_funct3(sid, ir_nid,
      NID_F3_LD, "LD?",
      ld_nid, format_comment("ld %s", (uint64_t) comment),
      decode_funct3(sid, ir_nid,
        NID_F3_LW, "LW?",
        lw_nid, format_comment("lw %s", (uint64_t) comment),
        decode_funct3(sid, ir_nid,
          NID_F3_LWU, "LWU?",
          lwu_nid, format_comment("lwu %s", (uint64_t) comment),
          decode_funct3(sid, ir_nid,
            NID_F3_LH, "LH?",
            lh_nid, format_comment("lh %s", (uint64_t) comment),
            decode_funct3(sid, ir_nid,
              NID_F3_LHU, "LHU?",
              lhu_nid, format_comment("lhu %s", (uint64_t) comment),
              decode_funct3(sid, ir_nid,
                NID_F3_LB, "LB?",
                lb_nid, format_comment("lb %s", (uint64_t) comment),
                decode_funct3(sid, ir_nid,
                  NID_F3_LBU, "LBU?",
                  lbu_nid, format_comment("lbu %s", (uint64_t) comment),
                  no_funct3_nid))))))),
    format_comment("load %s", (uint64_t) comment),
    other_opcode_nid);
}

uint64_t* decode_store(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* sd_nid, uint64_t* sw_nid,
  uint64_t* sh_nid, uint64_t* sb_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* other_opcode_nid) {
  return decode_opcode(sid, ir_nid,
    NID_OP_STORE, "STORE?",
    decode_funct3(sid, ir_nid,
      NID_F3_SD, "SD?",
      sd_nid, format_comment("sd %s", (uint64_t) comment),
      decode_funct3(sid, ir_nid,
        NID_F3_SW, "SW?",
        sw_nid, format_comment("sw %s", (uint64_t) comment),
        decode_funct3(sid, ir_nid,
          NID_F3_SH, "SH?",
          sh_nid, format_comment("sh %s", (uint64_t) comment),
          decode_funct3(sid, ir_nid,
            NID_F3_SB, "SB?",
            sb_nid, format_comment("sb %s", (uint64_t) comment),
            no_funct3_nid)))),
    format_comment("store %s", (uint64_t) comment),
    other_opcode_nid);
}

uint64_t* decode_branch(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* beq_nid, uint64_t* bne_nid,
  uint64_t* blt_nid, uint64_t* bge_nid,
  uint64_t* bltu_nid, uint64_t* bgeu_nid,
  uint64_t* branch_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* other_opcode_nid) {
  return decode_opcode(sid, ir_nid,
    NID_OP_BRANCH, "BRANCH?",
    decode_funct3_conditional(sid, ir_nid,
      NID_F3_BEQ, "BEQ?",
      beq_nid, branch_nid, format_comment("beq %s", (uint64_t) comment),
      decode_funct3_conditional(sid, ir_nid,
        NID_F3_BNE, "BNE?",
        bne_nid, branch_nid, format_comment("bne %s", (uint64_t) comment),
        decode_funct3_conditional(sid, ir_nid,
          NID_F3_BLT, "BLT?",
          blt_nid, branch_nid, format_comment("blt %s", (uint64_t) comment),
          decode_funct3_conditional(sid, ir_nid,
            NID_F3_BGE, "BGE?",
            bge_nid, branch_nid, format_comment("bge %s", (uint64_t) comment),
            decode_funct3_conditional(sid, ir_nid,
              NID_F3_BLTU, "BLTU?",
              bltu_nid, branch_nid, format_comment("bltu %s", (uint64_t) comment),
              decode_funct3_conditional(sid, ir_nid,
                NID_F3_BGEU, "BGEU?",
                bgeu_nid, branch_nid, format_comment("bgeu %s", (uint64_t) comment),
                no_funct3_nid)))))),
    format_comment("branch %s", (uint64_t) comment),
    other_opcode_nid);
}

uint64_t* decode_jal(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* jal_nid, char* comment,
  uint64_t* other_opcode_nid) {
  return decode_opcode(sid, ir_nid,
    NID_OP_JAL, "JAL?",
    jal_nid, format_comment("jal opcode %s", (uint64_t) comment),
    other_opcode_nid);
}

uint64_t* decode_jalr(uint64_t* sid, uint64_t* ir_nid,
  uint64_t* jalr_nid, char* comment,
  uint64_t* no_funct3_nid, uint64_t* other_opcode_nid) {
  return decode_opcode(sid, ir_nid,
    NID_OP_JALR, "JALR?",
    decode_funct3(sid, ir_nid,
      NID_F3_JALR, "JALR?",
      jalr_nid, format_comment("jalr funct3 %s", (uint64_t) comment),
      no_funct3_nid),
    format_comment("jalr opcode %s", (uint64_t) comment),
    other_opcode_nid);
}

uint64_t* decode_instruction(uint64_t* ir_nid) {
  return new_ternary(OP_ITE, SID_BOOLEAN,
    new_binary_boolean(OP_EQ, ir_nid, NID_ECALL_I, "ir == ECALL?"),
    NID_ECALL,
    decode_imm(SID_BOOLEAN, ir_nid,
      NID_ADDI,
      NID_SLTI,
      NID_SLTIU,
      NID_XORI,
      NID_ORI,
      NID_ANDI,
      NID_SLLI,
      NID_SRLI,
      NID_SRAI,
      "known?", NID_FALSE, NID_FALSE,
      decode_imm_32(SID_BOOLEAN, ir_nid,
        NID_ADDIW,
        NID_SLLIW,
        NID_SRLIW,
        NID_SRAIW,
        "known?", NID_FALSE, NID_FALSE,
        decode_op(SID_BOOLEAN, ir_nid,
          NID_ADD,
          NID_SUB,
          NID_SLT,
          NID_SLTU,
          NID_XOR,
          NID_OR,
          NID_AND,
          NID_SLL,
          NID_SRL,
          NID_SRA,
          "known?", NID_FALSE,
          decode_RV32M(SID_BOOLEAN, ir_nid,
            NID_MUL,
            NID_MULH,
            NID_MULHSU,
            NID_MULHU,
            NID_DIV,
            NID_DIVU,
            NID_REM,
            NID_REMU,
            "known?", NID_FALSE, NID_FALSE),
          decode_load(SID_BOOLEAN, ir_nid,
            NID_LD,
            NID_LW, NID_LWU,
            NID_LH, NID_LHU,
            NID_LB, NID_LBU,
            "known?", NID_FALSE,
            decode_store(SID_BOOLEAN, ir_nid,
              NID_SD,
              NID_SW, NID_SH, NID_SB, "known?", NID_FALSE,
              decode_branch(SID_BOOLEAN, ir_nid,
                NID_BEQ, NID_BNE,
                NID_BLT, NID_BGE,
                NID_BLTU, NID_BGEU,
                NID_TRUE, "known?", NID_FALSE,
                decode_jal(SID_BOOLEAN, ir_nid,
                  NID_JAL, "known?",
                  decode_jalr(SID_BOOLEAN, ir_nid,
                    NID_JALR, "known?", NID_FALSE,
                    decode_lui(SID_BOOLEAN, ir_nid,
                      NID_LUI, "known?",
                      decode_auipc(SID_BOOLEAN, ir_nid,
                        NID_AUIPC, "known?",
                        NID_FALSE)))))))))),
    "ecall known?");
}

uint64_t* get_rs1_value_plus_I_immediate(uint64_t* ir_nid) {
  return new_binary(OP_ADD, SID_MACHINE_WORD,
    load_register_value(get_instruction_rs1(ir_nid), "rs1 value"),
    get_instruction_I_immediate(ir_nid),
    "rs1 value + I-immediate");
}

uint64_t* imm_data_flow(uint64_t* ir_nid, uint64_t* other_data_flow_nid) {
  uint64_t* rs1_value_nid;
  uint64_t* rs1_value_single_word_nid;

  rs1_value_nid             = load_register_value(get_instruction_rs1(ir_nid), "rs1 value");
  rs1_value_single_word_nid = slice_single_word_from_machine_word(rs1_value_nid);

  return decode_imm(SID_MACHINE_WORD, ir_nid,
    get_rs1_value_plus_I_immediate(ir_nid),
    new_ext(OP_UEXT, SID_MACHINE_WORD,
      new_binary_boolean(OP_SLT,
        rs1_value_nid,
        get_instruction_I_immediate(ir_nid),
        "rs1 value < I-immediate?"),
      WORDSIZEINBITS - 1,
      "unsigned-extend Boolean to machine word"),
    new_ext(OP_UEXT, SID_MACHINE_WORD,
      new_binary_boolean(OP_ULT,
        rs1_value_nid,
        get_instruction_I_immediate(ir_nid),
        "rs1 value < I-immediate (unsigned)?"),
      WORDSIZEINBITS - 1,
      "unsigned-extend Boolean to machine word"),
    new_binary(OP_XOR, SID_MACHINE_WORD,
      rs1_value_nid,
      get_instruction_I_immediate(ir_nid),
      "rs1 value ^ I-immediate"),
    new_binary(OP_OR, SID_MACHINE_WORD,
      rs1_value_nid,
      get_instruction_I_immediate(ir_nid),
      "rs1 value | I-immediate"),
    new_binary(OP_AND, SID_MACHINE_WORD,
      rs1_value_nid,
      get_instruction_I_immediate(ir_nid),
      "rs1 value & I-immediate"),
    new_binary(OP_SLL, SID_MACHINE_WORD,
      rs1_value_nid,
      get_instruction_shamt(ir_nid),
      "rs1 value << shamt"),
    new_binary(OP_SRL, SID_MACHINE_WORD,
      rs1_value_nid,
      get_instruction_shamt(ir_nid),
      "rs1 value >> shamt"),
    new_binary(OP_SRA, SID_MACHINE_WORD,
      rs1_value_nid,
      get_instruction_shamt(ir_nid),
      "signed rs1 value >> shamt"),
    "imm register data flow",
    load_register_value(get_instruction_rd(ir_nid), "current unmodified rd value"),
    load_register_value(get_instruction_rd(ir_nid), "current unmodified rd value"),
    decode_imm_32(SID_MACHINE_WORD, ir_nid,
      extend_single_word_to_machine_word(OP_SEXT,
        new_binary(OP_ADD, SID_SINGLE_WORD,
          rs1_value_single_word_nid,
          get_instruction_I_immediate_32(ir_nid),
          "rs1 value + I-immediate-32")),
      extend_single_word_to_machine_word(OP_SEXT,
        new_binary(OP_SLL, SID_SINGLE_WORD,
          rs1_value_single_word_nid,
          get_instruction_shamt_32(ir_nid),
          "lower 32 bits of rs1 value << shamt-32")),
      extend_single_word_to_machine_word(OP_SEXT,
        new_binary(OP_SRL, SID_SINGLE_WORD,
          rs1_value_single_word_nid,
          get_instruction_shamt_32(ir_nid),
          "lower 32 bits of rs1 value >> shamt-32")),
      extend_single_word_to_machine_word(OP_SEXT,
        new_binary(OP_SRA, SID_SINGLE_WORD,
          rs1_value_single_word_nid,
          get_instruction_shamt_32(ir_nid),
          "signed lower 32 bits of rs1 value >> shamt-32")),
      "imm-32 register data flow",
      load_register_value(get_instruction_rd(ir_nid), "current unmodified rd value"),
      load_register_value(get_instruction_rd(ir_nid), "current unmodified rd value"),
      other_data_flow_nid));
}

uint64_t* op_data_flow(uint64_t* ir_nid, uint64_t* other_data_flow_nid) {
  uint64_t* rd_value_nid;

  uint64_t* rs1_value_nid;
  uint64_t* rs2_value_nid;

  rd_value_nid = load_register_value(get_instruction_rd(ir_nid), "current unmodified rd value");

  rs1_value_nid = load_register_value(get_instruction_rs1(ir_nid), "rs1 value");
  rs2_value_nid = load_register_value(get_instruction_rs2(ir_nid), "rs2 value");

  return decode_op(SID_MACHINE_WORD, ir_nid,
    new_binary(OP_ADD, SID_MACHINE_WORD,
      rs1_value_nid,
      rs2_value_nid,
      "rs1 value + rs2 value"),
    new_binary(OP_SUB, SID_MACHINE_WORD,
      rs1_value_nid,
      rs2_value_nid,
      "rs1 value - rs2 value"),
    new_ext(OP_UEXT, SID_MACHINE_WORD,
      new_binary_boolean(OP_SLT,
        rs1_value_nid,
        rs2_value_nid,
        "rs1 value < rs2 value?"),
      WORDSIZEINBITS - 1,
      "unsigned-extend Boolean to machine word"),
    new_ext(OP_UEXT, SID_MACHINE_WORD,
      new_binary_boolean(OP_ULT,
        rs1_value_nid,
        rs2_value_nid,
        "rs1 value < rs2 value (unsigned)?"),
      WORDSIZEINBITS - 1,
      "unsigned-extend Boolean to machine word"),
    new_binary(OP_XOR, SID_MACHINE_WORD,
      rs1_value_nid,
      rs2_value_nid,
      "rs1 value ^ rs2 value"),
    new_binary(OP_OR, SID_MACHINE_WORD,
      rs1_value_nid,
      rs2_value_nid,
      "rs1 value | rs2 value"),
    new_binary(OP_AND, SID_MACHINE_WORD,
      rs1_value_nid,
      rs2_value_nid,
      "rs1 value & rs2 value"),
    new_binary(OP_SLL, SID_MACHINE_WORD,
      rs1_value_nid,
      rs2_value_nid,
      "rs1 value << rs2 value"),
    new_binary(OP_SRL, SID_MACHINE_WORD,
      rs1_value_nid,
      rs2_value_nid,
      "rs1 value >> rs2 value"),
    new_binary(OP_SRA, SID_MACHINE_WORD,
      rs1_value_nid,
      rs2_value_nid,
      "signed rs1 value >> rs2 value"),
    "op register data flow",
    rd_value_nid,
    decode_RV32M(SID_MACHINE_WORD, ir_nid,
      new_binary(OP_MUL, SID_MACHINE_WORD,
        rs1_value_nid,
        rs2_value_nid,
        "rs1 value * rs2 value"),
      new_slice(SID_MACHINE_WORD,
        new_binary(OP_MUL, SID_DOUBLE_MACHINE_WORD,
          new_ext(OP_SEXT, SID_DOUBLE_MACHINE_WORD,
            rs1_value_nid, WORDSIZEINBITS, "sign-extend rs1 value to double machine word"),
          new_ext(OP_SEXT, SID_DOUBLE_MACHINE_WORD,
            rs2_value_nid, WORDSIZEINBITS, "sign-extend rs2 value to double machine word"),
          "double precision rs1 value * rs2 value"),
        2 * WORDSIZEINBITS - 1,
        WORDSIZEINBITS,
        "upper machine word"),
      new_slice(SID_MACHINE_WORD,
        new_binary(OP_MUL, SID_DOUBLE_MACHINE_WORD,
          new_ext(OP_SEXT, SID_DOUBLE_MACHINE_WORD,
            rs1_value_nid, WORDSIZEINBITS, "sign-extend rs1 value to double machine word"),
          new_ext(OP_UEXT, SID_DOUBLE_MACHINE_WORD,
            rs2_value_nid, WORDSIZEINBITS, "unsigned-extend rs2 value to double machine word"),
          "double precision rs1 value * rs2 value"),
        2 * WORDSIZEINBITS - 1,
        WORDSIZEINBITS,
        "upper machine word"),
      new_slice(SID_MACHINE_WORD,
        new_binary(OP_MUL, SID_DOUBLE_MACHINE_WORD,
          new_ext(OP_UEXT, SID_DOUBLE_MACHINE_WORD,
            rs1_value_nid, WORDSIZEINBITS, "unsigned-extend rs1 value to double machine word"),
          new_ext(OP_UEXT, SID_DOUBLE_MACHINE_WORD,
            rs2_value_nid, WORDSIZEINBITS, "unsigned-extend rs2 value to double machine word"),
          "double precision rs1 value * rs2 value"),
        2 * WORDSIZEINBITS - 1,
        WORDSIZEINBITS,
        "upper machine word"),
      new_binary(OP_SDIV, SID_MACHINE_WORD,
        rs1_value_nid,
        rs2_value_nid,
        "rs1 value / rs2 value"),
      new_binary(OP_UDIV, SID_MACHINE_WORD,
        rs1_value_nid,
        rs2_value_nid,
        "rs1 value / rs2 value (unsigned)"),
      new_binary(OP_SREM, SID_MACHINE_WORD,
        rs1_value_nid,
        rs2_value_nid,
        "rs1 value % rs2 value"),
      new_binary(OP_UREM, SID_MACHINE_WORD,
        rs1_value_nid,
        rs2_value_nid,
        "rs1 value % rs2 value (unsigned)"),
      "RV32M register data flow",
      rd_value_nid,
      rd_value_nid),
    other_data_flow_nid);
}

uint64_t* load_data_flow(uint64_t* ir_nid, uint64_t* memory_nid, uint64_t* other_data_flow_nid) {
  return decode_load(SID_MACHINE_WORD, ir_nid,
    load_double_word(get_rs1_value_plus_I_immediate(ir_nid), memory_nid),
    extend_single_word_to_machine_word(OP_SEXT,
      load_single_word(get_rs1_value_plus_I_immediate(ir_nid), memory_nid)),
    extend_single_word_to_machine_word(OP_UEXT,
      load_single_word(get_rs1_value_plus_I_immediate(ir_nid), memory_nid)),
    extend_half_word_to_machine_word(OP_SEXT,
      load_half_word(get_rs1_value_plus_I_immediate(ir_nid), memory_nid)),
    extend_half_word_to_machine_word(OP_UEXT,
      load_half_word(get_rs1_value_plus_I_immediate(ir_nid), memory_nid)),
    extend_byte_to_machine_word(OP_SEXT,
      load_byte(get_rs1_value_plus_I_immediate(ir_nid), memory_nid)),
    extend_byte_to_machine_word(OP_UEXT,
      load_byte(get_rs1_value_plus_I_immediate(ir_nid), memory_nid)),
    "register data flow",
    load_register_value(get_instruction_rd(ir_nid), "current unmodified rd value"),
    other_data_flow_nid);
}

uint64_t* load_no_seg_faults(uint64_t* ir_nid) {
  return decode_load(SID_BOOLEAN, ir_nid,
    is_range_in_main_memory(get_rs1_value_plus_I_immediate(ir_nid), NID_DOUBLE_WORD_SIZE),
    is_range_in_main_memory(get_rs1_value_plus_I_immediate(ir_nid), NID_SINGLE_WORD_SIZE),
    is_range_in_main_memory(get_rs1_value_plus_I_immediate(ir_nid), NID_SINGLE_WORD_SIZE),
    is_range_in_main_memory(get_rs1_value_plus_I_immediate(ir_nid), NID_HALF_WORD_SIZE),
    is_range_in_main_memory(get_rs1_value_plus_I_immediate(ir_nid), NID_HALF_WORD_SIZE),
    is_address_in_main_memory(get_rs1_value_plus_I_immediate(ir_nid)),
    is_address_in_main_memory(get_rs1_value_plus_I_immediate(ir_nid)),
    "no-seg-faults",
    NID_TRUE,
    NID_TRUE);
}

uint64_t* get_pc_value_plus_4(uint64_t* pc_nid) {
  return new_binary(OP_ADD, SID_MACHINE_WORD,
    pc_nid,
    NID_MACHINE_WORD_4,
    "pc value + 4");
}

uint64_t* jal_data_flow(uint64_t* pc_nid, uint64_t* ir_nid, uint64_t* other_data_flow_nid) {
  return decode_jal(SID_MACHINE_WORD, ir_nid,
    get_pc_value_plus_4(pc_nid),
    "register data flow",
    other_data_flow_nid);
}

uint64_t* jalr_data_flow(uint64_t* pc_nid, uint64_t* ir_nid, uint64_t* other_data_flow_nid) {
  return decode_jalr(SID_MACHINE_WORD, ir_nid,
    get_pc_value_plus_4(pc_nid),
    "register data flow",
    load_register_value(get_instruction_rd(ir_nid), "current unmodified rd value"),
    other_data_flow_nid);
}

uint64_t* lui_data_flow(uint64_t* ir_nid, uint64_t* other_data_flow_nid) {
  return decode_lui(SID_MACHINE_WORD, ir_nid,
    get_instruction_U_immediate(ir_nid),
    "register data flow",
    other_data_flow_nid);
}

uint64_t* get_pc_value_plus_U_immediate(uint64_t* pc_nid, uint64_t* ir_nid) {
  return new_binary(OP_ADD, SID_MACHINE_WORD,
    pc_nid,
    get_instruction_U_immediate(ir_nid),
    "pc value + U-immediate");
}

uint64_t* auipc_data_flow(uint64_t* pc_nid, uint64_t* ir_nid, uint64_t* other_data_flow_nid) {
  return decode_auipc(SID_MACHINE_WORD, ir_nid,
    get_pc_value_plus_U_immediate(pc_nid, ir_nid),
    "register data flow",
    other_data_flow_nid);
}

uint64_t* core_register_data_flow(uint64_t* pc_nid, uint64_t* ir_nid,
  uint64_t* register_file_nid, uint64_t* memory_nid) {
  uint64_t* opcode_nid;

  uint64_t* rd_nid;
  uint64_t* rd_value_nid;

  uint64_t* no_register_data_flow_nid;

  opcode_nid = get_instruction_opcode(ir_nid);

  rd_nid       = get_instruction_rd(ir_nid);
  rd_value_nid = load_register_value(rd_nid, "current rd value");

  no_register_data_flow_nid = new_binary_boolean(OP_OR,
    new_binary_boolean(OP_EQ, rd_nid, NID_ZR, "rd == register zero?"),
    new_binary_boolean(OP_OR,
      new_binary_boolean(OP_EQ, opcode_nid, NID_OP_STORE, "opcode == STORE?"),
      new_binary_boolean(OP_EQ, opcode_nid, NID_OP_BRANCH, "opcode == BRANCH?"),
      "STORE or BRANCH"), // redundant
    "rd == zero register or STORE or BRANCH");

  eval_core_rd_value_nid =
    imm_data_flow(ir_nid,
      op_data_flow(ir_nid,
        load_data_flow(ir_nid, memory_nid,
          jal_data_flow(pc_nid, ir_nid,
            jalr_data_flow(pc_nid, ir_nid,
              lui_data_flow(ir_nid,
                auipc_data_flow(pc_nid, ir_nid, rd_value_nid)))))));

  return new_ternary(OP_ITE, SID_REGISTER_STATE,
    no_register_data_flow_nid,
    register_file_nid,
    store_register_value(rd_nid, eval_core_rd_value_nid, register_file_nid, "write rd"),
    "update non-zero register");
}

uint64_t* get_rs1_value_plus_S_immediate(uint64_t* ir_nid) {
  return new_binary(OP_ADD, SID_MACHINE_WORD,
    load_register_value(get_instruction_rs1(ir_nid), "rs1 value"),
    get_instruction_S_immediate(ir_nid),
    "rs1 value + S-immediate");
}

uint64_t* store_data_flow(uint64_t* ir_nid, uint64_t* memory_nid, uint64_t* other_data_flow_nid) {
  uint64_t* rs2_value_nid;

  rs2_value_nid = load_register_value(get_instruction_rs2(ir_nid), "rs2 value");

  return decode_store(SID_MEMORY_STATE, ir_nid,
    store_double_word(get_rs1_value_plus_S_immediate(ir_nid),
      rs2_value_nid,
      memory_nid),
    store_single_word(get_rs1_value_plus_S_immediate(ir_nid),
      slice_single_word_from_machine_word(rs2_value_nid),
      memory_nid),
    store_half_word(get_rs1_value_plus_S_immediate(ir_nid),
      slice_half_word_from_machine_word(rs2_value_nid),
      memory_nid),
    store_byte(get_rs1_value_plus_S_immediate(ir_nid),
      slice_byte_from_machine_word(rs2_value_nid),
      memory_nid),
    "memory data flow",
    memory_nid,
    other_data_flow_nid);
}

uint64_t* store_no_seg_faults(uint64_t* ir_nid) {
  return decode_store(SID_BOOLEAN, ir_nid,
    is_range_in_main_memory(get_rs1_value_plus_S_immediate(ir_nid), NID_DOUBLE_WORD_SIZE),
    is_range_in_main_memory(get_rs1_value_plus_S_immediate(ir_nid), NID_SINGLE_WORD_SIZE),
    is_range_in_main_memory(get_rs1_value_plus_S_immediate(ir_nid), NID_HALF_WORD_SIZE),
    is_address_in_main_memory(get_rs1_value_plus_S_immediate(ir_nid)),
    "no-seg-faults",
    NID_TRUE,
    NID_TRUE);
}

uint64_t* core_memory_data_flow(uint64_t* ir_nid, uint64_t* memory_nid) {
  return store_data_flow(ir_nid, memory_nid, memory_nid);
}

uint64_t* get_pc_value_plus_SB_immediate(uint64_t* pc_nid, uint64_t* ir_nid) {
  return new_binary(OP_ADD, SID_MACHINE_WORD,
    pc_nid,
    get_instruction_SB_immediate(ir_nid),
    "pc value + SB-immediate");
}

uint64_t* branch_control_flow(uint64_t* pc_nid, uint64_t* ir_nid, uint64_t* other_control_flow_nid) {
  uint64_t* rs1_value_nid;
  uint64_t* rs2_value_nid;

  rs1_value_nid = load_register_value(get_instruction_rs1(ir_nid), "rs1 value");
  rs2_value_nid = load_register_value(get_instruction_rs2(ir_nid), "rs2 value");

  return decode_branch(SID_MACHINE_WORD, ir_nid,
    new_binary_boolean(OP_EQ, rs1_value_nid, rs2_value_nid, "rs1 value == rs2 value?"),
    new_binary_boolean(OP_NEQ, rs1_value_nid, rs2_value_nid, "rs1 value != rs2 value?"),
    new_binary_boolean(OP_SLT, rs1_value_nid, rs2_value_nid, "rs1 value < rs2 value?"),
    new_binary_boolean(OP_SGTE, rs1_value_nid, rs2_value_nid, "rs1 value >= rs2 value?"),
    new_binary_boolean(OP_ULT, rs1_value_nid, rs2_value_nid, "rs1 value < rs2 value (unsigned)?"),
    new_binary_boolean(OP_UGTE, rs1_value_nid, rs2_value_nid, "rs1 value >= rs2 value (unsigned)?"),
    get_pc_value_plus_SB_immediate(pc_nid, ir_nid), "pc-relative control flow",
    get_pc_value_plus_4(pc_nid),
    other_control_flow_nid);
}

uint64_t* get_pc_value_plus_UJ_immediate(uint64_t* pc_nid, uint64_t* ir_nid) {
  return new_binary(OP_ADD, SID_MACHINE_WORD,
    pc_nid,
    get_instruction_UJ_immediate(ir_nid),
    "pc value + UJ-immediate");
}

uint64_t* jal_control_flow(uint64_t* pc_nid, uint64_t* ir_nid, uint64_t* other_control_flow_nid) {
  return decode_jal(SID_MACHINE_WORD, ir_nid,
    get_pc_value_plus_UJ_immediate(pc_nid, ir_nid),
    "pc-relative control flow",
    other_control_flow_nid);
}

uint64_t* jalr_control_flow(uint64_t* pc_nid, uint64_t* ir_nid, uint64_t* other_control_flow_nid) {
  return decode_jalr(SID_MACHINE_WORD, ir_nid,
    new_binary(OP_AND, SID_MACHINE_WORD,
      get_rs1_value_plus_I_immediate(ir_nid),
      NID_LSB_MASK,
      "reset LSB"),
    "register-relative control flow",
    get_pc_value_plus_4(pc_nid),
    other_control_flow_nid);
}

uint64_t* core_control_flow(uint64_t* pc_nid, uint64_t* ir_nid) {
  return
    branch_control_flow(pc_nid, ir_nid,
      jal_control_flow(pc_nid, ir_nid,
        jalr_control_flow(pc_nid, ir_nid,
          get_pc_value_plus_4(pc_nid))));
}

// -----------------------------------------------------------------
// ----------------------------- CORE ------------------------------
// -----------------------------------------------------------------

void new_core_state() {
  if (SYNTHESIZE)
    initial_core_pc_nid = new_constant(OP_CONSTH, SID_MACHINE_WORD, code_start, 8, "initial pc value");
  else
    initial_core_pc_nid = new_constant(OP_CONSTH, SID_MACHINE_WORD, get_pc(current_context), 8, "entry pc value");

  state_core_pc_nid = new_input(OP_STATE, SID_MACHINE_WORD, "pc", "program counter");
  init_core_pc_nid  = new_binary(OP_INIT, SID_MACHINE_WORD, state_core_pc_nid, initial_core_pc_nid, "initial value of pc");
}

// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~
// -----------------------------------------------------------------
// ----------------------    R U N T I M E    ----------------------
// -----------------------------------------------------------------
// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~

// -----------------------------------------------------------------
// ------------------------ MODEL GENERATOR ------------------------
// -----------------------------------------------------------------

uint64_t* state_property(uint64_t* good_nid, uint64_t* bad_nid, char* symbol, char* comment) {
  if (SYNTHESIZE) {
    if (good_nid == UNUSED)
      good_nid = new_unary_boolean(OP_NOT, bad_nid, "asserting");

    return new_property(OP_CONSTRAINT, good_nid, symbol, comment);
  } else {
    if (bad_nid == UNUSED)
      bad_nid = new_unary_boolean(OP_NOT, good_nid, "targeting");

    return new_property(OP_BAD, bad_nid, symbol, comment);
  }
}

void kernel(uint64_t* pc_nid, uint64_t* ir_nid, uint64_t* memory_nid) {
  uint64_t* active_ecall_nid;

  uint64_t* a7_value_nid;

  uint64_t* exit_syscall_nid;
  uint64_t* active_exit_nid;

  uint64_t* brk_syscall_nid;
  uint64_t* active_brk_nid;

  uint64_t* openat_syscall_nid;
  uint64_t* active_openat_nid;

  uint64_t* read_syscall_nid;
  uint64_t* active_read_nid;

  uint64_t* write_syscall_nid;
  uint64_t* active_write_nid;

  uint64_t* a0_value_nid;

  uint64_t* new_program_break_nid;
  uint64_t* new_file_descriptor_nid;

  uint64_t* a2_value_nid;

  uint64_t* more_bytes_to_read_nid;
  uint64_t* more_readable_bytes_nid;
  uint64_t* more_readable_bytes_to_read_nid;

  uint64_t* incremented_read_bytes_nid;
  uint64_t* more_than_one_byte_to_read_nid;
  uint64_t* more_than_one_readable_byte_nid;
  uint64_t* more_than_one_readable_byte_to_read_nid;

  uint64_t* read_return_value_nid;

  uint64_t* a1_value_nid;

  // system call ABI control flow

  active_ecall_nid = new_binary_boolean(OP_EQ, ir_nid, NID_ECALL_I, "ir == ECALL?");

  a7_value_nid = load_register_value(NID_A7, "a7 value");

  exit_syscall_nid = new_binary_boolean(OP_EQ, a7_value_nid, NID_EXIT_SYSCALL_ID, "a7 == exit syscall ID?");
  active_exit_nid  = new_binary_boolean(OP_AND, active_ecall_nid, exit_syscall_nid, "active exit system call");

  brk_syscall_nid = new_binary_boolean(OP_EQ, a7_value_nid, NID_BRK_SYSCALL_ID, "a7 == brk syscall ID?");
  active_brk_nid  = new_binary_boolean(OP_AND, active_ecall_nid, brk_syscall_nid, "active brk system call");

  openat_syscall_nid = new_binary_boolean(OP_EQ, a7_value_nid, NID_OPENAT_SYSCALL_ID, "a7 == openat syscall ID?");
  active_openat_nid  = new_binary_boolean(OP_AND, active_ecall_nid, openat_syscall_nid, "active openat system call");

  read_syscall_nid = new_binary_boolean(OP_EQ, a7_value_nid, NID_READ_SYSCALL_ID, "a7 == read syscall ID?");
  active_read_nid  = new_binary_boolean(OP_AND, active_ecall_nid, read_syscall_nid, "active read system call");

  write_syscall_nid = new_binary_boolean(OP_EQ, a7_value_nid, NID_WRITE_SYSCALL_ID, "a7 == write syscall ID?");
  active_write_nid  = new_binary_boolean(OP_AND, active_ecall_nid, write_syscall_nid, "active write system call");

  // system call ABI data flow

  a0_value_nid = load_register_value(NID_A0, "a0 value");

  // update brk kernel state

  new_program_break_nid =
    new_ternary(OP_ITE, SID_MACHINE_WORD,
      new_binary_boolean(OP_AND,
        new_binary_boolean(OP_UGTE,
          a0_value_nid,
          state_program_break_nid,
          "new program break >= current program break?"),
        new_binary_boolean(OP_ULTE,
          a0_value_nid,
          NID_HEAP_END,
          "new program break <= end of heap segment?"),
        "is new program break in heap segment?"),
      a0_value_nid,
      state_program_break_nid,
      "update a0 if new program break is in heap segment");

  next_program_break_nid =
    new_binary(OP_NEXT, SID_MACHINE_WORD,
      state_program_break_nid,
      new_ternary(OP_ITE, SID_MACHINE_WORD,
        active_brk_nid,
        new_program_break_nid,
        state_program_break_nid,
        "new program break"),
      "new program break");

  // update openat kernel state

  new_file_descriptor_nid = new_unary(OP_INC, SID_MACHINE_WORD,
    state_file_descriptor_nid,
    "increment file descriptor");

  next_file_descriptor_nid =
    new_binary(OP_NEXT, SID_MACHINE_WORD,
      state_file_descriptor_nid,
      new_ternary(OP_ITE, SID_MACHINE_WORD,
        active_openat_nid,
        new_file_descriptor_nid,
        state_file_descriptor_nid,
        "new file descriptor"),
      "new file descriptor");

  // system call ABI data flow

  a2_value_nid = load_register_value(NID_A2, "a2 value");

  // update read kernel state

  more_bytes_to_read_nid =
    new_binary_boolean(OP_ULT,
      state_read_bytes_nid,
      a2_value_nid,
      "more bytes to read as requested in a2");

  more_readable_bytes_nid =
    new_binary_boolean(OP_UGT,
      state_readable_bytes_nid,
      NID_MACHINE_WORD_0,
      "more readable bytes");

  more_readable_bytes_to_read_nid =
    new_binary_boolean(OP_AND,
      more_bytes_to_read_nid,
      more_readable_bytes_nid,
      "can and still would like to read more bytes"),

  next_readable_bytes_nid =
    new_binary(OP_NEXT, SID_MACHINE_WORD,
      state_readable_bytes_nid,
      new_ternary(OP_ITE, SID_MACHINE_WORD,
        new_binary_boolean(OP_AND,
          active_read_nid,
          more_readable_bytes_to_read_nid,
          "still reading system call"),
        new_unary(OP_DEC, SID_MACHINE_WORD,
          state_readable_bytes_nid,
          "decrement readable bytes"),
        state_readable_bytes_nid,
        "decrement readable bytes if system call is still reading"),
      "readable bytes");

  incremented_read_bytes_nid =
    new_unary(OP_INC,
      SID_MACHINE_WORD,
      state_read_bytes_nid,
      "increment bytes already read by read system call");

  more_than_one_byte_to_read_nid =
    new_binary_boolean(OP_ULT,
      incremented_read_bytes_nid,
      a2_value_nid,
      "more than one byte to read as requested in a2");

  more_than_one_readable_byte_nid =
    new_binary_boolean(OP_UGT,
      state_readable_bytes_nid,
      NID_MACHINE_WORD_1,
      "more than one readable byte");

  more_than_one_readable_byte_to_read_nid =
    new_binary_boolean(OP_AND,
      more_than_one_byte_to_read_nid,
      more_than_one_readable_byte_nid,
      "can and still would like to read more than one byte");

  next_read_bytes_nid =
    new_binary(OP_NEXT, SID_MACHINE_WORD,
      state_read_bytes_nid,
      new_ternary(OP_ITE, SID_MACHINE_WORD,
        new_binary_boolean(OP_AND,
          active_read_nid,
          more_than_one_readable_byte_to_read_nid,
          "active read system call"),
        incremented_read_bytes_nid,
        NID_MACHINE_WORD_0,
        "increment bytes already read if read system call is active"),
      "bytes already read in active read system call");

  // kernel and non-kernel control flow

  eval_core_pc_nid = new_ternary(OP_ITE, SID_MACHINE_WORD,
    new_binary_boolean(OP_AND,
      active_ecall_nid,
      new_binary_boolean(OP_OR,
        exit_syscall_nid,
        new_binary_boolean(OP_AND,
          read_syscall_nid,
          more_than_one_readable_byte_to_read_nid,
          "ongoing read system call"),
        "ongoing exit or read system call"),
      "active system call"),
    pc_nid,
    eval_core_non_kernel_pc_nid,
    "update program counter unless in kernel mode");

  // kernel register data flow

  read_return_value_nid = new_ternary(OP_ITE, SID_MACHINE_WORD,
    new_binary_boolean(OP_UGT,
      a2_value_nid,
      NID_MACHINE_WORD_0,
      "more than 0 bytes to read"),
    new_ternary(OP_ITE, SID_MACHINE_WORD,
      more_readable_bytes_nid,
      new_ternary(OP_ITE, SID_MACHINE_WORD,
        more_than_one_byte_to_read_nid,
        new_ternary(OP_ITE, SID_MACHINE_WORD,
          more_than_one_readable_byte_nid,
          a0_value_nid,
          incremented_read_bytes_nid,
          "return number of bytes read so far + 1 if there is only one more readable byte"),
        a2_value_nid,
        "return a2 if number of bytes read so far is a2 - 1 and there are still readable bytes"),
      NID_MACHINE_WORD_MINUS_1,
      "return -1 if a2 > 0 and there are no readable bytes when starting to read"),
    NID_MACHINE_WORD_0,
    "return 0 if a2 == 0");

  // kernel and non-kernel register data flow

  eval_core_register_data_flow_nid = new_ternary(OP_ITE, SID_REGISTER_STATE,
    active_ecall_nid,
    new_ternary(OP_ITE, SID_REGISTER_STATE,
      brk_syscall_nid,
      store_register_value(
        NID_A0,
        new_program_break_nid,
        state_register_file_nid,
        "store new program break in a0"),
      new_ternary(OP_ITE, SID_REGISTER_STATE,
        openat_syscall_nid,
        store_register_value(
          NID_A0,
          new_file_descriptor_nid,
          state_register_file_nid,
          "store new file descriptor in a0"),
        new_ternary(OP_ITE, SID_REGISTER_STATE,
          new_binary_boolean(OP_AND,
            read_syscall_nid,
            new_unary_boolean(OP_NOT,
              more_than_one_readable_byte_to_read_nid,
              "read system call returns if there is at most one more byte to read"),
            "update a0 when read system call returns"),
          store_register_value(
            NID_A0,
            read_return_value_nid,
            state_register_file_nid,
            "store read return value in a0"),
          new_ternary(OP_ITE, SID_REGISTER_STATE,
            write_syscall_nid,
            store_register_value(
              NID_A0,
              a2_value_nid,
              state_register_file_nid,
              "store write return value in a0"),
            state_register_file_nid,
            "write system call register data flow"),
          "read system call register data flow"),
        "openat system call register data flow"),
      "brk system call register data flow"),
    eval_core_non_kernel_register_data_flow_nid,
    "register data flow");

  // system call ABI data flow

  a1_value_nid = load_register_value(NID_A1, "a1 value");

  // kernel and non-kernel memory data flow

  eval_core_memory_data_flow_nid = new_ternary(OP_ITE, SID_MEMORY_STATE,
    new_binary_boolean(OP_AND,
      active_read_nid,
      more_readable_bytes_to_read_nid,
      "more input bytes to read"),
    store_byte(new_binary(OP_ADD, SID_MACHINE_WORD,
      a1_value_nid,
      state_read_bytes_nid,
      "a1 + number of already read_bytes"),
      new_input(OP_INPUT, SID_BYTE, "read-input-byte", "input byte by read system call"),
      memory_nid),
    eval_core_non_kernel_memory_data_flow_nid,
    "main memory data flow");

  // kernel properties

  brk_seg_faulting_nid = state_property(
    UNUSED,
    new_binary_boolean(OP_AND,
      active_brk_nid,
      new_binary_boolean(OP_UGT,
        a0_value_nid,
        NID_HEAP_END,
        "new program break > end of heap segment?"),
      "new program break is above heap segment with active brk system call"),
    "brk-seg-fault",
    "possible brk segmentation fault");

  // TODO: validate openat arguments other than filename

  openat_seg_faulting_nid = state_property(
    UNUSED,
    new_binary_boolean(OP_AND,
      active_openat_nid,
      new_unary_boolean(OP_NOT,
        is_range_in_heap_segment(a1_value_nid, NID_MAX_STRING_LENGTH),
        "openat system call access outside of heap segment"),
      "accessing filename may cause segmentation fault"),
    "openat-seg-fault",
    "possible openat segmentation fault");

  // TODO: further validate read arguments

  read_seg_faulting_nid = state_property(
    UNUSED,
    new_binary_boolean(OP_AND,
      new_binary_boolean(OP_AND,
        active_read_nid,
        new_binary_boolean(OP_EQ,
          state_read_bytes_nid,
          NID_MACHINE_WORD_0,
          "have bytes been read yet?"),
        "no bytes read yet by active read system call"),
      new_unary_boolean(OP_NOT,
        is_range_in_heap_segment(a1_value_nid, a2_value_nid),
        "read system call access outside of heap segment"),
      "storing bytes to be read may cause segmentation fault"),
    "read-seg-fault",
    "possible read segmentation fault");

  // TODO: further validate write arguments

  write_seg_faulting_nid = state_property(
    UNUSED,
    new_binary_boolean(OP_AND,
      active_write_nid,
      new_unary_boolean(OP_NOT,
        is_range_in_heap_segment(a1_value_nid, a2_value_nid),
        "write system call access outside of heap segment"),
      "loading bytes to be written may cause segmentation fault"),
    "write-seg-fault",
    "possible write segmentation fault");

  is_syscall_id_known_nid = state_property(
    UNUSED,
    new_binary_boolean(OP_AND,
      active_ecall_nid,
      new_binary_boolean(OP_AND,
        new_binary_boolean(OP_NEQ, a7_value_nid, NID_EXIT_SYSCALL_ID, "a7 != exit syscall ID?"),
        new_binary_boolean(OP_AND,
          new_binary_boolean(OP_NEQ, a7_value_nid, NID_BRK_SYSCALL_ID, "a7 != brk syscall ID?"),
          new_binary_boolean(OP_AND,
            new_binary_boolean(OP_NEQ, a7_value_nid, NID_OPENAT_SYSCALL_ID, "a7 != openat syscall ID?"),
            new_binary_boolean(OP_AND,
              new_binary_boolean(OP_NEQ, a7_value_nid, NID_READ_SYSCALL_ID, "a7 != read syscall ID?"),
              new_binary_boolean(OP_NEQ, a7_value_nid, NID_WRITE_SYSCALL_ID, "a7 != write syscall ID?"),
              "a7 != read or write syscall ID"),
            "a7 != openat or read or write syscall ID"),
          "a7 != brk or openat or read or write syscall ID"),
        "a7 != exit or brk or openat or read or write syscall ID"),
      "active ecall and a7 != known syscall ID"),
    "unknown-syscall-ID",
    "unknown syscall ID");

  bad_exit_code_nid = new_property(OP_BAD,
    new_binary_boolean(OP_AND,
      active_exit_nid,
      new_binary_boolean(OP_EQ,
        a0_value_nid,
        new_constant(OP_CONSTD, SID_MACHINE_WORD,
          bad_exit_code,
          0,
          format_comment("bad exit code %ld", bad_exit_code)),
        "actual exit code == bad exit code?"),
      "active exit system call with bad exit code"),
    "b3", format_comment("exit(%ld)", bad_exit_code));
}

void rotor() {
  uint64_t* ir_nid;
  uint64_t* known_instructions_nid;

  new_segmentation();

  new_core_state();
  new_register_file_state();

  new_code_segment();
  new_memory_state();

  new_kernel_state(1);

  // fetch

  ir_nid = fetch_instruction(state_core_pc_nid);

  // decode

  known_instructions_nid = decode_instruction(ir_nid);

  // non-kernel control flow

  eval_core_non_kernel_pc_nid = core_control_flow(state_core_pc_nid, ir_nid);

  // non-kernel register data flow

  eval_core_non_kernel_register_data_flow_nid =
    core_register_data_flow(state_core_pc_nid, ir_nid, state_register_file_nid, state_main_memory_nid);

  // non-kernel memory data flow

  eval_core_non_kernel_memory_data_flow_nid = core_memory_data_flow(ir_nid, state_main_memory_nid);

  // kernel

  kernel(state_core_pc_nid, ir_nid, state_main_memory_nid);

  // update control flow

  next_core_pc_nid = new_binary(OP_NEXT, SID_MACHINE_WORD,
    state_core_pc_nid,
    eval_core_pc_nid,
    "program counter");

  // update register data flow

  next_register_file_nid = new_binary(OP_NEXT, SID_REGISTER_STATE,
    state_register_file_nid,
    eval_core_register_data_flow_nid,
    "register file");

  // update memory data flow

  next_main_memory_nid = new_binary(OP_NEXT, SID_MEMORY_STATE,
    state_main_memory_nid,
    eval_core_memory_data_flow_nid,
    "main memory");

  // state properties

  illegal_instruction_nid = state_property(
    UNUSED,
    decode_illegal_shift_imm(SID_BOOLEAN, ir_nid,
      NID_TRUE,
      NID_TRUE,
      NID_TRUE,
      "there?", NID_FALSE, NID_FALSE,
      NID_FALSE),
    "illegal-instruction",
    "illegal instruction");

  is_instruction_known_nid = state_property(
    known_instructions_nid,
    UNUSED,
    "known-instructions",
    "known instructions");

  next_fetch_unaligned_nid = state_property(
    new_binary_boolean(OP_EQ,
      new_binary(OP_AND, SID_MACHINE_WORD,
        eval_core_pc_nid,
        NID_INSTRUCTION_WORD_SIZE_MASK,
        "next pc alignment"),
      NID_MACHINE_WORD_0,
      "next pc unaligned"),
    UNUSED,
    "fetch-unaligned",
    "imminent unaligned fetch");

  next_fetch_seg_faulting_nid = state_property(
    is_address_in_code_segment(eval_core_pc_nid),
    UNUSED,
    "fetch-seg-fault",
    "imminent fetch segmentation fault");

  load_seg_faulting_nid = state_property(
    load_no_seg_faults(ir_nid),
    UNUSED,
    "load-seg-fault",
    "load segmentation fault");

  store_seg_faulting_nid = state_property(
    store_no_seg_faults(ir_nid),
    UNUSED,
    "store-seg-fault",
    "store segmentation fault");

  stack_seg_faulting_nid = state_property(
    new_binary_boolean(OP_OR,
      new_binary_boolean(OP_NEQ, get_instruction_rd(ir_nid), NID_SP, "rd != sp?"),
      is_address_in_stack_segment(eval_core_rd_value_nid),
      "rd != sp or new sp value is in stack segment"),
    UNUSED,
    "stack-seg-fault",
    "stack segmentation fault");

  if (RV32M)
    division_by_zero_nid = state_property(
      UNUSED,
      decode_opcode(SID_BOOLEAN, ir_nid,
        NID_OP_OP, "OP?",
        new_binary_boolean(OP_AND,
          decode_RV32M(SID_BOOLEAN, ir_nid,
            NID_FALSE,
            NID_FALSE,
            NID_FALSE,
            NID_FALSE,
            NID_DIV,
            NID_DIVU,
            NID_REM,
            NID_REMU,
            "or just div or divu or rem or remu?", NID_FALSE, NID_FALSE),
          new_binary_boolean(OP_EQ,
            load_register_value(get_instruction_rs2(ir_nid), "rs2 value"),
            NID_MACHINE_WORD_0,
            "rs2 value == zero?"),
          "div or divu or rem or remu by zero?"),
        "division or remainder by zero?", NID_FALSE),
      "division-by-zero",
      "division by zero");

  exclude_a0_from_rd_nid = state_property(
    new_binary_boolean(OP_NEQ,
      get_instruction_rd(ir_nid),
      NID_A0,
      "rd != a0"),
    UNUSED,
    "exclude-a0-from-rd",
    "only brk and read system call may update a0");
}

void output_model() {
  w = w
    + dprintf(output_fd, "; %s\n\n", SELFIE_URL)
    + dprintf(output_fd, "; BTOR2 file %s generated by %s\n\n", model_name, selfie_name);

  print_interface_sorts();
  print_interface_kernel();

  print_register_sorts();
  print_memory_sorts();

  print_segmentation();

  print_break("\n; program counter\n\n");

  print_line(initial_core_pc_nid);
  print_line(init_core_pc_nid);

  print_register_file_state();

  print_code_segment();
  print_memory_state();

  print_break("\n; kernel state\n\n");

  print_line(init_program_break_nid);

  print_break("\n");

  print_line(init_file_descriptor_nid);

  print_break("\n");

  print_line(readable_bytes_nid);
  print_line(init_readable_bytes_nid);

  print_break("\n");

  print_line(init_read_bytes_nid);

  print_break("\n; non-kernel control flow\n\n");

  print_line(eval_core_non_kernel_pc_nid);

  print_break("\n; update kernel state\n\n");

  print_line(next_program_break_nid);

  print_break("\n");

  print_line(next_file_descriptor_nid);

  print_break("\n");

  print_line(next_readable_bytes_nid);

  print_break("\n");

  print_line(next_read_bytes_nid);

  print_break("\n; kernel and non-kernel control flow\n\n");

  print_line(eval_core_pc_nid);

  print_break("\n; update program counter\n\n");

  print_line(next_core_pc_nid);

  print_break("\n; non-kernel register data flow\n\n");

  print_line(eval_core_non_kernel_register_data_flow_nid);

  print_break("\n; kernel and non-kernel register data flow\n\n");

  print_line(eval_core_register_data_flow_nid);

  print_break("\n; update register data flow\n\n");

  print_line(next_register_file_nid);

  print_break("\n; non-kernel memory data flow\n\n");

  print_line(eval_core_non_kernel_memory_data_flow_nid);

  print_break("\n; kernel and non-kernel memory data flow\n\n");

  print_line(eval_core_memory_data_flow_nid);

  print_break("\n; update memory data flow\n\n");

  print_line(next_main_memory_nid);

  print_break("\n; state properties\n\n");

  if (IS64BITTARGET == 0) {
    print_line(illegal_instruction_nid);

    print_break("\n");
  }

  print_line(is_instruction_known_nid);

  print_break("\n");

  print_line(next_fetch_unaligned_nid);

  print_break("\n");

  print_line(next_fetch_seg_faulting_nid);

  print_break("\n");

  print_line(load_seg_faulting_nid);

  print_break("\n");

  print_line(store_seg_faulting_nid);

  print_break("\n");

  print_line(stack_seg_faulting_nid);

  if (RV32M) {
    print_break("\n");

    print_line(division_by_zero_nid);
  }

  //print_break("\n");

  //print_line(exclude_a0_from_rd_nid);

  print_break("\n");

  print_line(brk_seg_faulting_nid);

  print_break("\n");

  print_line(openat_seg_faulting_nid);

  print_break("\n");

  print_line(read_seg_faulting_nid);

  print_break("\n");

  print_line(write_seg_faulting_nid);

  print_break("\n");

  print_line(is_syscall_id_known_nid);

  print_break("\n");

  print_line(bad_exit_code_nid);
}

uint64_t selfie_model() {
  if (string_compare(argument, "-")) {
    if (number_of_remaining_arguments() > 0) {
      bad_exit_code = atoi(peek_argument(0));

      // TODO: introduce console arguments for allowances

      heap_allowance  = WORDSIZE;
      stack_allowance = WORDSIZE; // stack allowance must be greater than zero

      if (code_size > 0) {
        reset_interpreter();
        reset_profiler();
        reset_microkernel();

        init_memory(1);

        current_context = create_context(MY_CONTEXT, 0);

        // assert: number_of_remaining_arguments() > 0

        boot_loader(current_context);

        restore_context(current_context);

        do_switch(current_context, TIMEROFF);

        // assert: allowances are multiples of word size

        if (get_program_break(current_context) - get_heap_seg_start(current_context) > heap_allowance)
          heap_allowance = round_up(get_program_break(current_context) - get_heap_seg_start(current_context), PAGESIZE);

        heap_start = get_heap_seg_start(current_context);
        heap_size  = heap_allowance;

        if (VIRTUALMEMORYSIZE * GIGABYTE - *(get_regs(current_context) + REG_SP) > stack_allowance)
          stack_allowance = round_up(VIRTUALMEMORYSIZE * GIGABYTE - *(get_regs(current_context) + REG_SP), PAGESIZE);

        stack_start = VIRTUALMEMORYSIZE * GIGABYTE - stack_allowance;
        stack_size  = stack_allowance;

        // assert: stack_start >= heap_start + heap_size > 0

        SYNTHESIZE = 0;
      } else {
        code_start = 4096;
        code_size  = 7 * 4;

        data_start = 8192;
        data_size  = 0;

        heap_allowance = 10;

        heap_start = 12288;
        heap_size  = heap_allowance;

        stack_start = VIRTUALMEMORYSIZE * GIGABYTE - stack_allowance;
        stack_size  = stack_allowance;

        // assert: stack_start >= heap_start + heap_size > 0

        SYNTHESIZE = 1;
      }

      init_model_generator();

      rotor();

      // use extension ".btor2" in name of SMT-LIB file
      model_name = "riscu-machine.btor2";

      // assert: model_name is mapped and not longer than MAX_FILENAME_LENGTH

      model_fd = open_write_only(model_name, S_IRUSR_IWUSR_IRGRP_IROTH);

      if (signed_less_than(model_fd, 0)) {
        printf("%s: could not create model file %s\n", selfie_name, model_name);

        exit(EXITCODE_IOERROR);
      }

      reset_library();

      output_name = model_name;
      output_fd   = model_fd;

      output_model();

      output_name = (char*) 0;
      output_fd   = 1;

      printf("%s: %lu characters of model formulae written into %s\n", selfie_name, w, model_name);

      printf("%s: ################################################################################\n", selfie_name);

      return EXITCODE_NOERROR;
    } else
      return EXITCODE_BADARGUMENTS;
  } else
    return EXITCODE_BADARGUMENTS;
}

// -----------------------------------------------------------------
// ----------------------------- MAIN ------------------------------
// -----------------------------------------------------------------

int main(int argc, char** argv) {
  uint64_t exit_code;

  init_selfie((uint64_t) argc, (uint64_t*) argv);

  init_library();
  init_system();
  init_target();
  init_kernel();

  exit_code = selfie(1);

  if (exit_code == EXITCODE_MOREARGUMENTS)
    exit_code = selfie_model();

  return exit_selfie(exit_code, " - exit_code ...");
}