#ifndef ID3_H_INCLUDED
#define ID3_H_INCLUDED


/*
    Struttura dati info dataset
*/
struct dsinfo_t
{
    char            	*name;
    long            	value;
	long				column;
    struct dsinfo_t   	*next;
    struct dsinfo_t   	*prev;
};

/*
	Struttura dati foglia
*/
typedef struct node_tag
{
	long				winvalue;
	long				tot_attrib;
	long				*avail_attrib;
	long				tot_samples;
	long				*samples;
	long				tot_nodes;
	struct node_tag	*nodes;
} node_t;



#endif // ID3_H_INCLUDED
