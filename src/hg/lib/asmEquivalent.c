/* asmEquivalent.c was originally generated by the autoSql program, which also 
 * generated asmEquivalent.h and asmEquivalent.sql.  This module links the database and
 * the RAM representation of objects. */

#include "common.h"
#include "linefile.h"
#include "dystring.h"
#include "jksql.h"
#include "asmEquivalent.h"



char *asmEquivalentCommaSepFieldNames = "source,destination,sourceAuthority,destinationAuthority,matchCount,sourceCount,destinationCount";

/* definitions for sourceAuthority column */
static char *values_sourceAuthority[] = {"ensembl", "ucsc", "genbank", "refseq", NULL};
static struct hash *valhash_sourceAuthority = NULL;

/* definitions for destinationAuthority column */
static char *values_destinationAuthority[] = {"ensembl", "ucsc", "genbank", "refseq", NULL};
static struct hash *valhash_destinationAuthority = NULL;

void asmEquivalentStaticLoad(char **row, struct asmEquivalent *ret)
/* Load a row from asmEquivalent table into ret.  The contents of ret will
 * be replaced at the next call to this function. */
{

ret->source = row[0];
ret->destination = row[1];
ret->sourceAuthority = sqlEnumParse(row[2], values_sourceAuthority, &valhash_sourceAuthority);
ret->destinationAuthority = sqlEnumParse(row[3], values_destinationAuthority, &valhash_destinationAuthority);
ret->matchCount = sqlLongLong(row[4]);
ret->sourceCount = sqlLongLong(row[5]);
ret->destinationCount = sqlLongLong(row[6]);
}

struct asmEquivalent *asmEquivalentLoadByQuery(struct sqlConnection *conn, char *query)
/* Load all asmEquivalent from table that satisfy the query given.
 * Where query is of the form 'select * from example where something=something'
 * or 'select example.* from example, anotherTable where example.something =
 * anotherTable.something'.
 * Dispose of this with asmEquivalentFreeList(). */
{
struct asmEquivalent *list = NULL, *el;
struct sqlResult *sr;
char **row;

sr = sqlGetResult(conn, query);
while ((row = sqlNextRow(sr)) != NULL)
    {
    el = asmEquivalentLoad(row);
    slAddHead(&list, el);
    }
slReverse(&list);
sqlFreeResult(&sr);
return list;
}

void asmEquivalentSaveToDb(struct sqlConnection *conn, struct asmEquivalent *el, char *tableName, int updateSize)
/* Save asmEquivalent as a row to the table specified by tableName.
 * As blob fields may be arbitrary size updateSize specifies the approx size
 * of a string that would contain the entire query. Arrays of native types are
 * converted to comma separated strings and loaded as such, User defined types are
 * inserted as NULL. This function automatically escapes quoted strings for mysql. */
{
struct dyString *update = newDyString(updateSize);
sqlDyStringPrintf(update, "insert into %s values ( '%s','%s',(null),(null),%lld,%lld,%lld)",
	tableName,  el->source,  el->destination,  el->sourceAuthority,  el->destinationAuthority,  el->matchCount,  el->sourceCount,  el->destinationCount);
sqlUpdate(conn, update->string);
freeDyString(&update);
}

struct asmEquivalent *asmEquivalentLoad(char **row)
/* Load a asmEquivalent from row fetched with select * from asmEquivalent
 * from database.  Dispose of this with asmEquivalentFree(). */
{
struct asmEquivalent *ret;

AllocVar(ret);
ret->source = cloneString(row[0]);
ret->destination = cloneString(row[1]);
ret->sourceAuthority = sqlEnumParse(row[2], values_sourceAuthority, &valhash_sourceAuthority);
ret->destinationAuthority = sqlEnumParse(row[3], values_destinationAuthority, &valhash_destinationAuthority);
ret->matchCount = sqlLongLong(row[4]);
ret->sourceCount = sqlLongLong(row[5]);
ret->destinationCount = sqlLongLong(row[6]);
return ret;
}

struct asmEquivalent *asmEquivalentLoadAll(char *fileName)
/* Load all asmEquivalent from a whitespace-separated file.
 * Dispose of this with asmEquivalentFreeList(). */
{
struct asmEquivalent *list = NULL, *el;
struct lineFile *lf = lineFileOpen(fileName, TRUE);
char *row[7];

while (lineFileRow(lf, row))
    {
    el = asmEquivalentLoad(row);
    slAddHead(&list, el);
    }
lineFileClose(&lf);
slReverse(&list);
return list;
}

struct asmEquivalent *asmEquivalentLoadAllByChar(char *fileName, char chopper)
/* Load all asmEquivalent from a chopper separated file.
 * Dispose of this with asmEquivalentFreeList(). */
{
struct asmEquivalent *list = NULL, *el;
struct lineFile *lf = lineFileOpen(fileName, TRUE);
char *row[7];

while (lineFileNextCharRow(lf, chopper, row, ArraySize(row)))
    {
    el = asmEquivalentLoad(row);
    slAddHead(&list, el);
    }
lineFileClose(&lf);
slReverse(&list);
return list;
}

struct asmEquivalent *asmEquivalentCommaIn(char **pS, struct asmEquivalent *ret)
/* Create a asmEquivalent out of a comma separated string.
 * This will fill in ret if non-null, otherwise will
 * return a new asmEquivalent */
{
char *s = *pS;

if (ret == NULL)
    AllocVar(ret);
ret->source = sqlStringComma(&s);
ret->destination = sqlStringComma(&s);
ret->sourceAuthority = sqlEnumComma(&s, values_sourceAuthority, &valhash_sourceAuthority);
ret->destinationAuthority = sqlEnumComma(&s, values_destinationAuthority, &valhash_destinationAuthority);
ret->matchCount = sqlLongLongComma(&s);
ret->sourceCount = sqlLongLongComma(&s);
ret->destinationCount = sqlLongLongComma(&s);
*pS = s;
return ret;
}

void asmEquivalentFree(struct asmEquivalent **pEl)
/* Free a single dynamically allocated asmEquivalent such as created
 * with asmEquivalentLoad(). */
{
struct asmEquivalent *el;

if ((el = *pEl) == NULL) return;
freeMem(el->source);
freeMem(el->destination);
freez(pEl);
}

void asmEquivalentFreeList(struct asmEquivalent **pList)
/* Free a list of dynamically allocated asmEquivalent's */
{
struct asmEquivalent *el, *next;

for (el = *pList; el != NULL; el = next)
    {
    next = el->next;
    asmEquivalentFree(&el);
    }
*pList = NULL;
}

void asmEquivalentOutput(struct asmEquivalent *el, FILE *f, char sep, char lastSep)
/* Print out asmEquivalent.  Separate fields with sep. Follow last field with lastSep. */
{
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->source);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->destination);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
sqlEnumPrint(f, el->sourceAuthority, values_sourceAuthority);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
sqlEnumPrint(f, el->destinationAuthority, values_destinationAuthority);
if (sep == ',') fputc('"',f);
fputc(sep,f);
fprintf(f, "%lld", el->matchCount);
fputc(sep,f);
fprintf(f, "%lld", el->sourceCount);
fputc(sep,f);
fprintf(f, "%lld", el->destinationCount);
fputc(lastSep,f);
}

void asmEquivalentJsonOutput(struct asmEquivalent *el, FILE *f)
/* Print out asmEquivalent in JSON format. */
{
fputc('{',f);
fputc('"',f);
fprintf(f,"source");
fputc('"',f);
fputc(':',f);
fputc('"',f);
fprintf(f, "%s", el->source);
fputc('"',f);
fputc(',',f);
fputc('"',f);
fprintf(f,"destination");
fputc('"',f);
fputc(':',f);
fputc('"',f);
fprintf(f, "%s", el->destination);
fputc('"',f);
fputc(',',f);
fputc('"',f);
fprintf(f,"sourceAuthority");
fputc('"',f);
fputc(':',f);
fputc('"',f);
sqlEnumPrint(f, el->sourceAuthority, values_sourceAuthority);
fputc('"',f);
fputc(',',f);
fputc('"',f);
fprintf(f,"destinationAuthority");
fputc('"',f);
fputc(':',f);
fputc('"',f);
sqlEnumPrint(f, el->destinationAuthority, values_destinationAuthority);
fputc('"',f);
fputc(',',f);
fputc('"',f);
fprintf(f,"matchCount");
fputc('"',f);
fputc(':',f);
fprintf(f, "%lld", el->matchCount);
fputc(',',f);
fputc('"',f);
fprintf(f,"sourceCount");
fputc('"',f);
fputc(':',f);
fprintf(f, "%lld", el->sourceCount);
fputc(',',f);
fputc('"',f);
fprintf(f,"destinationCount");
fputc('"',f);
fputc(':',f);
fprintf(f, "%lld", el->destinationCount);
fputc('}',f);
}

/* -------------------------------- End autoSql Generated Code -------------------------------- */
