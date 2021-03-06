# mafSummary.sql was originally generated by the autoSql program, which also 
# generated mafSummary.c and mafSummary.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#Positions and scores for alignment blocks
CREATE TABLE mafSummary (
    bin smallint unsigned not null,	# bin field for speed
    chrom varchar(255) not null,	# Chromosome
    chromStart int unsigned not null,	# Start position in chromosome
    chromEnd int unsigned not null,	# End position in chromosome
    src varchar(255) not null,	# Sequence name or database of alignment
    score float not null,	# Floating point score.
    leftStatus char(1) not null,    # Gap/break annotation for preceding block
    rightStatus char(1) not null,   # Gap/break annotation for following block
              #Indices
    INDEX(chrom(20),bin)
);
