# knownAttrs.sql was originally generated by the autoSql program, which also 
# generated knownAttrs.c and knownAttrs.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#Fields in Gencode attrs table that aren't in kgXref
CREATE TABLE knownAttrs (
    kgID varchar(255) not null,	# Known Gene ID
    geneId varchar(255) not null,	# ENSG* locus identifier
    geneStatus varchar(255) not null,	# KNOWN or NOVEL
    geneType varchar(255) not null,	# gene function
    transcriptName varchar(255) not null,	# transcript Name
    transcriptType varchar(255) not null,	# transcript Type
    transcriptStatus varchar(255) not null,	# KNOWN or NOVEL or PUTATIVE
    havanaGeneId varchar(255) not null,	# Havana project Id
    ccdsId varchar(255) not null,	# CCDS project Id
    supportLevel varchar(255) not null,	# transcript support level
    transcriptClass varchar(255) not null,	# pseudo, nonCoding, coding, or problem
              #Indices
    PRIMARY KEY(kgID)
);