/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "op.h"

NUM *suma_1_svc(struct NUM *argp, struct svc_req *rqstp)
{
	//static double  result;
	static struct NUM result;


	 result.i = (*argp).i + (*argp).j;

	

	return &result;
}

NUM *
producto_1_svc(struct NUM *argp, struct svc_req *rqstp)
{
	static struct NUM result;
	
	 result.i = (*argp).i * (*argp).j;

	return &result;
}

NUM *
cociente_1_svc(struct NUM *argp, struct svc_req *rqstp)
{
	static struct NUM result;

	
	 result.i = (*argp).i / (*argp).j;

	return &result;
}
