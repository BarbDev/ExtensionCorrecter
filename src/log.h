#ifndef LOG_H_
#define LOG_H_

/* File tracking stuff */
void incrementDirParsed(void);
void incrementDirFailed(void);
void incrementFilesParsed(void);
unsigned int getNbeDirParsed(void);
unsigned int getNbeDirFailed(void);
unsigned int getNbeFilesParsed(void);
unsigned int getNbeFilesModif(void);
unsigned int getNbeFilesFailed(void);
void addFileToModif(const char* file);
void addFileToFail(const char* file);
void freeLists(void);
void printModifList(void);
void clearConsoleBuffer(void);
char getInputCh(void);
void displayProgress(const char* currDir, const char* currFile, unsigned char params);

#endif /* LOG_H_ */