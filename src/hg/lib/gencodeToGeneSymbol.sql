# gencodeToGeneSymbol.sql was originally generated by the autoSql program, which also 
# generated gencodeToGeneSymbol.c and gencodeToGeneSymbol.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#GENCODE transcript to official gene symbol.  For human, this is the HUGO Gene Nomenclature Committee (HGNC) gene symbo.  For mouse, this is the Mouse Genome Informatics (MGI) gene symbol.
CREATE TABLE gencodeToGeneSymbol (
    transcriptId varchar(255) not null,	# GENCODE transcript identifier
    symbol varchar(255) not null,	# HGNC/MGI gene symbol
    geneId varchar(255) not null,	# HGNC/MGI symbol id used by database
              #Indices
    index(transcriptId)
);