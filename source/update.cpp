#include "header.h"

int updateUF(char userDir[30], int oldvernum)
{
	char tmpSTR[31];
	FILE *userFile;
	sprintf(tmpSTR, "%s/userdata.ruf", userDir);
	userFile = fopen(tmpSTR, "r");
	if (oldvernum == 0)
	{
		std::cout << "Updating File Version to 1\n";
		FILE *fp;
		char ustring[30];
		char ustring2[30];
		sprintf(ustring, "%s/userdata.ruf", userDir);
		sprintf(ustring2, "%s/temp.rtf", userDir);
		char dummyc[30];
		fp = fopen(ustring, "r");
		fseek(fp, 0, SEEK_SET);
		char name[21], pass[21];
		fscanf(fp, "%s %s %s", dummyc, dummyc, name);
		fscanf(fp, "%s %s %s", dummyc, dummyc, pass);
		fclose(fp);
		FILE *fileptr1, *fileptr2;
		fileptr1 = fopen(ustring, "r");
		fileptr2 = fopen(ustring2, "w");
		fscanf(fileptr1, "%s %s %s %s %s %s", dummyc, dummyc, dummyc, dummyc, dummyc, dummyc);
		while(true)
		{
			//ch = getc(fileptr1);
			//putc(ch, fileptr2);
			fscanf(fileptr1, "%s", dummyc);
			if (strcmp(dummyc, "msg") == 0)
			{
				fprintf(fileptr2, "%s ", dummyc);
				for(int i = 0; i < 2; i++)
				{
					fscanf(fileptr1, "%s", dummyc);
					fprintf(fileptr2, "%s ", dummyc);
				}
				break;
			}
			fprintf(fileptr2, "%s ", dummyc);
		}
		fprintf(fileptr2, "-EOF-");
		fclose(fileptr1);
		fclose(fileptr2);
		remove(ustring);
		fileptr1 = fopen(ustring, "w");
		fileptr2 = fopen(ustring2, "r");
		fprintf(fileptr1, "name = %s\n", name);
		fprintf(fileptr1, "pass = %s\n", pass);
		fprintf(fileptr1, "version = 1\n");
		while(true)
		{
			//ch = getc(fileptr2);
			//putc(ch, fileptr1);
			fscanf(fileptr2, "%s", dummyc);
			if(strcmp(dummyc, "-EOF-") == 0)
				break;
			else
				fprintf(fileptr1, "%s ", dummyc);
		}
		fprintf(fileptr1, "-EOF-");
		fclose(fileptr1);
		fclose(fileptr2);
		remove(ustring2);
		oldvernum = 1;
	}
	if (oldvernum == 1)
	{
		std::cout << "Updating File Version 1 to 2\n";
		FILE *fp;
		char ustring[30];
		char ustring2[30];
		sprintf(ustring, "%s/userdata.ruf", userDir);
		sprintf(ustring2, "%s/temp.rtf", userDir);
		char dummyc[30];
		fp = fopen(ustring, "r");
		fseek(fp, 0, SEEK_SET);
		char name[21], pass[21];
		fscanf(fp, "%s %s %s", dummyc, dummyc, name);
		fscanf(fp, "%s %s %s", dummyc, dummyc, pass);
		fclose(fp);
		FILE *fileptr1, *fileptr2;
		fileptr1 = fopen(ustring, "r");
		fileptr2 = fopen(ustring2, "w");
		fscanf(fileptr1, "%s %s %s %s %s %s %s %s %s", dummyc, dummyc, dummyc, dummyc, dummyc, dummyc, dummyc, dummyc, dummyc);
		while(true)
		{
			//ch = getc(fileptr1);
			//putc(ch, fileptr2);
			fscanf(fileptr1, "%s", dummyc);
			if (strcmp(dummyc, "-EOF-") == 0)
				break;
			else
				fprintf(fileptr2, "%s ", dummyc);
		}
		fprintf(fileptr2, "-EOF-");
		fclose(fileptr1);
		fclose(fileptr2);
		remove(ustring);
		fileptr1 = fopen(ustring, "w");
		fileptr2 = fopen(ustring2, "r");
		fprintf(fileptr1, "name = %s\n", name);
		fprintf(fileptr1, "pass = %s\n", pass);
		fprintf(fileptr1, "version = 2\n");
		while(true)
		{
			//ch = getc(fileptr2);
			//putc(ch, fileptr1);
			fscanf(fileptr2, "%s", dummyc);
			if(strcmp(dummyc, "-EOF-") == 0)
				break;
			else
				fprintf(fileptr1, "%s ", dummyc);
		}
		fprintf(fileptr1, "Media = 1\n");
		fprintf(fileptr1, "-EOF-");
		fclose(fileptr1);
		fclose(fileptr2);
		remove(ustring2);
		oldvernum = 2;
	}
	fclose(userFile);
	return 0;
}

int updateSF(char userDir[30], bool hasRunU)
{
	return 0;
}