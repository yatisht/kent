# asmEquivalent.sql was originally generated by the autoSql program, which also 
# generated asmEquivalent.c and asmEquivalent.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#Equivalence relationship of assembly versions, Ensembl: UCSC, NCBI genbank/refseq
CREATE TABLE asmEquivalent (
    source varchar(255) not null,	# assembly name
    destination varchar(255) not null,	# equivalent assembly name
    sourceAuthority enum("ensembl", "ucsc", "genbank", "refseq") not null,	# origin of source assembly
    destinationAuthority enum("ensembl", "ucsc", "genbank", "refseq") not null,	# origin of equivalent assembly
    matchCount bigint not null,	# number of exactly matching sequences
    sourceCount bigint not null,	# number of sequences in source assembly
    destinationCount bigint not null,	# number of sequences in equivalent assembly
              #Indices
    INDEX (source),
    INDEX (destination)
);