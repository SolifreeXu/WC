#ifndef WC_H
#define WC_H

int charCount(const char *fileAbsolutePath);
int wordCount(const char *fileAbsolutePath);
int lineCount(const char *fileAbsolutePath);
int multiLineCount(const char *fileAbsolutePath, int &codeLineNum, int &blankLineNum, int &commentLineNum);
int filesCount(int argc, char *argv[]);

#endif // WC_H
