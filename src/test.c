#include <clang-c/Index.h> 
#include <stdio.h>

int main(int argc, const char * const * argv) {
    CXIndex Index = clang_createIndex(0, 0);
    CXTranslationUnit TU = clang_parseTranslationUnit(Index, 0, argv, argc, 0, 0, CXTranslationUnit_None);
    for (int i = 0, n = clang_getNumDiagnostics(TU); i != n; i++)
    {
        CXDiagnostic Diag = clang_getDiagnostic(TU, i);
        CXString String = clang_formatDiagnostic(Diag, clang_defaultDiagnosticDisplayOptions());
        fprintf(stderr, "%s\n", clang_getCString(String));
        clang_disposeString(String);
    }
    clang_disposeTranslationUnit(TU);
    clang_disposeIndex(Index);
    return 0;
}