# gencodeToEntrezGene.sql was originally generated by the autoSql program, which also 
# generated gencodeToEntrezGene.c and gencodeToEntrezGene.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#The NCBI Entrez gene id associated with GENCODE transcript annotation
CREATE TABLE gencodeToEntrezGene (
    transcriptId varchar(255) not null,	# GENCODE transcript identifier
    entrezGeneId int not null,	# Entrez gene id
              #Indices
    index(transcriptId)
);