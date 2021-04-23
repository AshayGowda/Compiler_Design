Introduction and Problem Statement
To implement a Compiler for C using Lex, Yacc and C as the language to code the compiler in. The input could be any valid C Program with Functions, Conditions and Looping constructs. The output would be the expected output from “gcc” when run on a standard Unix shell.
Architecture of the Language
The syntax is the same as C, for all the constructs that we are focusing on. We have made sure to implement the semantics of the language as close to C as possible. We have handled all errors and border cases for every construct in our language and have added many error checking mechanisms too.
Grammar
We used a regular Backus Normal Form Grammar to develop the entire language. Most of the productions inspired by ISO C and a few constructs that we created to provide some novelty to our project.
Design Strategies and Implementation Details Symbol Table Generation
We are using a linked list of structures to implement our Symbol Table. It is created on the Heap and is called to a print function just before the compilation ends. The print function outputs a formatted symbol table to STDOUT.A node of the symbol table has the following structure.
1. Line
2. Name
3. Scope (0 for Global, -1 for Main)
4. Value
5. ID
6. Data Type
Which is displayed in a tabular form during the end of the program to represent the symbol table that has been generated during the first phase.
We store the entire table in a dynamic list-queue data structure.
Intermediate Code Generation
Intermediate Code Generation is implemented using various functions and data structures that are used to generate and store the Intermediate Codes. We have a list of structures of type Quadruple to store the Quadruples generated by the compiler. Several functions are used to accomplish the required processing. We then use a print function that neatly formats the IC and prints it onto STDOUT.
Code Optimisation :
We have done 5 optimisations in our project.They are :
• Eliminate dead code
• Subexpression elimination
• Constant Folding
• Constant Propagation
• Loop Invariant code outside loop
These were done using python language as it was easy to split the lines and it had various inbuilt methods which we can make use of to optimise the intermediate code.This give out Optim_ICG.txt file which contains the optimized the code

Error Handling
Various Errors are handled in our compiler such as syntactic and semantic errors.The yyerror function handles the errors and gives out respective error messages with the respective line no’s.

Results
Our Compiler has been able to compile and generate code for the Sample Input files pretty accurately. It can detect a plethora of errors and satisfactorily compile and produce optimal code. We are confident that by the end of the semester, we will be able to build a reputable compiler for C.
Possible Shortcoming
The compiler we built is a mini-compiler and doesn’t entirely mimic or compile all C code. We haven’t implemented STLs that make up the majority of C. And the functions we have generated have been optimized specifically for the current language and grammar that has been elaborated on in this document. The generated code may be a bit buffed up compared to a highly optimized version of the same, generated by an Official C Compiler.


Conclusions
We can conclude that a satisfactorily accurate compiler can be build using Lex and Yacc for a number of different languages spreading across multiple genres. We can conclude that the various phases of a standard compiler can be built and implemented using these tools and by following all regulations, a standard compiler can be built for almost any language.
Further Enhancements
We have included two construct specified and plan to add a few more techniques we have learned during the duration of this course that may not be present in the standard C compiler.

Build and Run :
lex lexer.l
yacc -d parser.y
gcc y.tab.c -ll -ly ./a.out input.c
python optimization.py
