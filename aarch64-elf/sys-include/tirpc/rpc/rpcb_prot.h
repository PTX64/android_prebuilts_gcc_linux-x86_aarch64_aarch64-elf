/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _RPCB_PROT_H_RPCGEN
#define _RPCB_PROT_H_RPCGEN

#include <rpc/rpc.h>

#ifndef IXDR_GET_INT32
#define IXDR_GET_INT32(buf) IXDR_GET_LONG((buf))
#endif
#ifndef IXDR_PUT_INT32
#define IXDR_PUT_INT32(buf, v) IXDR_PUT_LONG((buf), (v))
#endif
#ifndef IXDR_GET_U_INT32
#define IXDR_GET_U_INT32(buf) IXDR_GET_U_LONG((buf))
#endif
#ifndef IXDR_PUT_U_INT32
#define IXDR_PUT_U_INT32(buf, v) IXDR_PUT_U_LONG((buf), (v))
#endif
/*
 * $FreeBSD: src/include/rpc/rpcb_prot.x,v 1.3 2002/03/13 10:29:06 obrien Exp $
 *
 * Copyright (c) 2009, Sun Microsystems, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name of Sun Microsystems, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * Copyright (c) 1988 by Sun Microsystems, Inc.
 */
/* from rpcb_prot.x */

/* #pragma ident	"@(#)rpcb_prot.x	1.5	94/04/29 SMI" */

#ifndef _KERNEL


/*
 * The following procedures are supported by the protocol in version 3:
 *
 * RPCBPROC_NULL() returns ()
 * 	takes nothing, returns nothing
 *
 * RPCBPROC_SET(rpcb) returns (bool_t)
 * 	TRUE is success, FALSE is failure.  Registers the tuple
 *	[prog, vers, address, owner, netid].
 *	Finds out owner and netid information on its own.
 *
 * RPCBPROC_UNSET(rpcb) returns (bool_t)
 *	TRUE is success, FALSE is failure.  Un-registers tuple
 *	[prog, vers, netid].  addresses is ignored.
 *	If netid is NULL, unregister all.
 *
 * RPCBPROC_GETADDR(rpcb) returns (string).
 *	0 is failure.  Otherwise returns the universal address where the
 *	triple [prog, vers, netid] is registered.  Ignore address and owner.
 *
 * RPCBPROC_DUMP() RETURNS (rpcblist_ptr)
 *	used to dump the entire rpcbind maps
 *
 * RPCBPROC_CALLIT(rpcb_rmtcallargs)
 * 	RETURNS (rpcb_rmtcallres);
 * 	Calls the procedure on the remote machine.  If it is not registered,
 *	this procedure is quiet; i.e. it does not return error information!!!
 *	This routine only passes null authentication parameters.
 *	It has no interface to xdr routines for RPCBPROC_CALLIT.
 *
 * RPCBPROC_GETTIME() returns (int).
 *	Gets the remote machines time
 *
 * RPCBPROC_UADDR2TADDR(strint) RETURNS (struct netbuf)
 *	Returns the netbuf address from universal address.
 *
 * RPCBPROC_TADDR2UADDR(struct netbuf) RETURNS (string)
 *	Returns the universal address from netbuf address.
 *
 * END OF RPCBIND VERSION 3 PROCEDURES
 */
/*
 * Except for RPCBPROC_CALLIT, the procedures above are carried over to
 * rpcbind version 4.  Those below are added or modified for version 4.
 * NOTE: RPCBPROC_BCAST HAS THE SAME FUNCTIONALITY AND PROCEDURE NUMBER
 * AS RPCBPROC_CALLIT.
 *
 * RPCBPROC_BCAST(rpcb_rmtcallargs)
 * 	RETURNS (rpcb_rmtcallres);
 * 	Calls the procedure on the remote machine.  If it is not registered,
 *	this procedure IS quiet; i.e. it DOES NOT return error information!!!
 *	This routine should be used for broadcasting and nothing else.
 *
 * RPCBPROC_GETVERSADDR(rpcb) returns (string).
 *	0 is failure.  Otherwise returns the universal address where the
 *	triple [prog, vers, netid] is registered.  Ignore address and owner.
 *	Same as RPCBPROC_GETADDR except that if the given version number
 *	is not available, the address is not returned.
 *
 * RPCBPROC_INDIRECT(rpcb_rmtcallargs)
 * 	RETURNS (rpcb_rmtcallres);
 * 	Calls the procedure on the remote machine.  If it is not registered,
 *	this procedure is NOT quiet; i.e. it DOES return error information!!!
 * 	as any normal application would expect.
 *
 * RPCBPROC_GETADDRLIST(rpcb) returns (rpcb_entry_list_ptr).
 *	Same as RPCBPROC_GETADDR except that it returns a list of all the
 *	addresses registered for the combination (prog, vers) (for all
 *	transports).
 *
 * RPCBPROC_GETSTAT(void) returns (rpcb_stat_byvers)
 *	Returns the statistics about the kind of requests received by rpcbind.
 */

/*
 * A mapping of (program, version, network ID) to address
 */

struct rpcb {
	rpcprog_t r_prog;
	rpcvers_t r_vers;
	char *r_netid;
	char *r_addr;
	char *r_owner;
};
typedef struct rpcb rpcb;
#ifdef __cplusplus 
extern "C" bool_t xdr_rpcb(XDR *, rpcb*);
#elif __STDC__ 
extern  bool_t xdr_rpcb(XDR *, rpcb*);
#else /* Old Style C */ 
bool_t xdr_rpcb();
#endif /* Old Style C */ 


typedef rpcb RPCB;


/*
 * A list of mappings
 *
 * Below are two definitions for the rpcblist structure.  This is done because
 * xdr_rpcblist() is specified to take a struct rpcblist **, rather than a
 * struct rpcblist * that rpcgen would produce.  One version of the rpcblist
 * structure (actually called rp__list) is used with rpcgen, and the other is
 * defined only in the header file for compatibility with the specified
 * interface.
 */

struct rp__list {
	rpcb rpcb_map;
	struct rp__list *rpcb_next;
};
typedef struct rp__list rp__list;
#ifdef __cplusplus 
extern "C" bool_t xdr_rp__list(XDR *, rp__list*);
#elif __STDC__ 
extern  bool_t xdr_rp__list(XDR *, rp__list*);
#else /* Old Style C */ 
bool_t xdr_rp__list();
#endif /* Old Style C */ 


typedef rp__list *rpcblist_ptr;
#ifdef __cplusplus 
extern "C" bool_t xdr_rpcblist_ptr(XDR *, rpcblist_ptr*);
#elif __STDC__ 
extern  bool_t xdr_rpcblist_ptr(XDR *, rpcblist_ptr*);
#else /* Old Style C */ 
bool_t xdr_rpcblist_ptr();
#endif /* Old Style C */ 


typedef struct rp__list rpcblist;
typedef struct rp__list RPCBLIST;

#ifndef __cplusplus
struct rpcblist {
 RPCB rpcb_map;
 struct rpcblist *rpcb_next;
};
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern bool_t xdr_rpcblist(XDR *, rpcblist**);
#ifdef __cplusplus
}
#endif


/*
 * Arguments of remote calls
 */

struct rpcb_rmtcallargs {
	rpcprog_t prog;
	rpcvers_t vers;
	rpcproc_t proc;
	struct {
		u_int args_len;
		char *args_val;
	} args;
};
typedef struct rpcb_rmtcallargs rpcb_rmtcallargs;
#ifdef __cplusplus 
extern "C" bool_t xdr_rpcb_rmtcallargs(XDR *, rpcb_rmtcallargs*);
#elif __STDC__ 
extern  bool_t xdr_rpcb_rmtcallargs(XDR *, rpcb_rmtcallargs*);
#else /* Old Style C */ 
bool_t xdr_rpcb_rmtcallargs();
#endif /* Old Style C */ 


/*
 * Client-side only representation of rpcb_rmtcallargs structure.
 *
 * The routine that XDRs the rpcb_rmtcallargs structure must deal with the
 * opaque arguments in the "args" structure.  xdr_rpcb_rmtcallargs() needs to
 * be passed the XDR routine that knows the args' structure.  This routine
 * doesn't need to go over-the-wire (and it wouldn't make sense anyway) since
 * the application being called already knows the args structure.  So we use a
 * different "XDR" structure on the client side, r_rpcb_rmtcallargs, which
 * includes the args' XDR routine.
 */
struct r_rpcb_rmtcallargs {
 rpcprog_t prog;
 rpcvers_t vers;
 rpcproc_t proc;
 struct {
 u_int args_len;
 char *args_val;
 } args;
 xdrproc_t xdr_args; /* encodes args */
};


/*
 * Results of the remote call
 */

struct rpcb_rmtcallres {
	char *addr;
	struct {
		u_int results_len;
		char *results_val;
	} results;
};
typedef struct rpcb_rmtcallres rpcb_rmtcallres;
#ifdef __cplusplus 
extern "C" bool_t xdr_rpcb_rmtcallres(XDR *, rpcb_rmtcallres*);
#elif __STDC__ 
extern  bool_t xdr_rpcb_rmtcallres(XDR *, rpcb_rmtcallres*);
#else /* Old Style C */ 
bool_t xdr_rpcb_rmtcallres();
#endif /* Old Style C */ 


/*
 * Client-side only representation of rpcb_rmtcallres structure.
 */
struct r_rpcb_rmtcallres {
 char *addr;
 struct {
 u_int32_t results_len;
 char *results_val;
 } results;
 xdrproc_t xdr_res; /* decodes results */
};

/*
 * rpcb_entry contains a merged address of a service on a particular
 * transport, plus associated netconfig information.  A list of rpcb_entrys
 * is returned by RPCBPROC_GETADDRLIST.  See netconfig.h for values used
 * in r_nc_* fields.
 */

struct rpcb_entry {
	char *r_maddr;
	char *r_nc_netid;
	u_int r_nc_semantics;
	char *r_nc_protofmly;
	char *r_nc_proto;
};
typedef struct rpcb_entry rpcb_entry;
#ifdef __cplusplus 
extern "C" bool_t xdr_rpcb_entry(XDR *, rpcb_entry*);
#elif __STDC__ 
extern  bool_t xdr_rpcb_entry(XDR *, rpcb_entry*);
#else /* Old Style C */ 
bool_t xdr_rpcb_entry();
#endif /* Old Style C */ 


/*
 * A list of addresses supported by a service.
 */

struct rpcb_entry_list {
	rpcb_entry rpcb_entry_map;
	struct rpcb_entry_list *rpcb_entry_next;
};
typedef struct rpcb_entry_list rpcb_entry_list;
#ifdef __cplusplus 
extern "C" bool_t xdr_rpcb_entry_list(XDR *, rpcb_entry_list*);
#elif __STDC__ 
extern  bool_t xdr_rpcb_entry_list(XDR *, rpcb_entry_list*);
#else /* Old Style C */ 
bool_t xdr_rpcb_entry_list();
#endif /* Old Style C */ 


typedef rpcb_entry_list *rpcb_entry_list_ptr;
#ifdef __cplusplus 
extern "C" bool_t xdr_rpcb_entry_list_ptr(XDR *, rpcb_entry_list_ptr*);
#elif __STDC__ 
extern  bool_t xdr_rpcb_entry_list_ptr(XDR *, rpcb_entry_list_ptr*);
#else /* Old Style C */ 
bool_t xdr_rpcb_entry_list_ptr();
#endif /* Old Style C */ 


/*
 * rpcbind statistics
 */

#define rpcb_highproc_2 RPCBPROC_CALLIT
#define rpcb_highproc_3 RPCBPROC_TADDR2UADDR
#define rpcb_highproc_4 RPCBPROC_GETSTAT
#define RPCBSTAT_HIGHPROC 13
#define RPCBVERS_STAT 3
#define RPCBVERS_4_STAT 2
#define RPCBVERS_3_STAT 1
#define RPCBVERS_2_STAT 0

/* Link list of all the stats about getport and getaddr */

struct rpcbs_addrlist {
	rpcprog_t prog;
	rpcvers_t vers;
	int success;
	int failure;
	char *netid;
	struct rpcbs_addrlist *next;
};
typedef struct rpcbs_addrlist rpcbs_addrlist;
#ifdef __cplusplus 
extern "C" bool_t xdr_rpcbs_addrlist(XDR *, rpcbs_addrlist*);
#elif __STDC__ 
extern  bool_t xdr_rpcbs_addrlist(XDR *, rpcbs_addrlist*);
#else /* Old Style C */ 
bool_t xdr_rpcbs_addrlist();
#endif /* Old Style C */ 


/* Link list of all the stats about rmtcall */

struct rpcbs_rmtcalllist {
	rpcprog_t prog;
	rpcvers_t vers;
	rpcproc_t proc;
	int success;
	int failure;
	int indirect;
	char *netid;
	struct rpcbs_rmtcalllist *next;
};
typedef struct rpcbs_rmtcalllist rpcbs_rmtcalllist;
#ifdef __cplusplus 
extern "C" bool_t xdr_rpcbs_rmtcalllist(XDR *, rpcbs_rmtcalllist*);
#elif __STDC__ 
extern  bool_t xdr_rpcbs_rmtcalllist(XDR *, rpcbs_rmtcalllist*);
#else /* Old Style C */ 
bool_t xdr_rpcbs_rmtcalllist();
#endif /* Old Style C */ 


typedef int rpcbs_proc[RPCBSTAT_HIGHPROC];
#ifdef __cplusplus 
extern "C" bool_t xdr_rpcbs_proc(XDR *, rpcbs_proc);
#elif __STDC__ 
extern  bool_t xdr_rpcbs_proc(XDR *, rpcbs_proc);
#else /* Old Style C */ 
bool_t xdr_rpcbs_proc();
#endif /* Old Style C */ 


typedef rpcbs_addrlist *rpcbs_addrlist_ptr;
#ifdef __cplusplus 
extern "C" bool_t xdr_rpcbs_addrlist_ptr(XDR *, rpcbs_addrlist_ptr*);
#elif __STDC__ 
extern  bool_t xdr_rpcbs_addrlist_ptr(XDR *, rpcbs_addrlist_ptr*);
#else /* Old Style C */ 
bool_t xdr_rpcbs_addrlist_ptr();
#endif /* Old Style C */ 


typedef rpcbs_rmtcalllist *rpcbs_rmtcalllist_ptr;
#ifdef __cplusplus 
extern "C" bool_t xdr_rpcbs_rmtcalllist_ptr(XDR *, rpcbs_rmtcalllist_ptr*);
#elif __STDC__ 
extern  bool_t xdr_rpcbs_rmtcalllist_ptr(XDR *, rpcbs_rmtcalllist_ptr*);
#else /* Old Style C */ 
bool_t xdr_rpcbs_rmtcalllist_ptr();
#endif /* Old Style C */ 


struct rpcb_stat {
	rpcbs_proc info;
	int setinfo;
	int unsetinfo;
	rpcbs_addrlist_ptr addrinfo;
	rpcbs_rmtcalllist_ptr rmtinfo;
};
typedef struct rpcb_stat rpcb_stat;
#ifdef __cplusplus 
extern "C" bool_t xdr_rpcb_stat(XDR *, rpcb_stat*);
#elif __STDC__ 
extern  bool_t xdr_rpcb_stat(XDR *, rpcb_stat*);
#else /* Old Style C */ 
bool_t xdr_rpcb_stat();
#endif /* Old Style C */ 


/*
 * One rpcb_stat structure is returned for each version of rpcbind
 * being monitored.
 */

typedef rpcb_stat rpcb_stat_byvers[RPCBVERS_STAT];
#ifdef __cplusplus 
extern "C" bool_t xdr_rpcb_stat_byvers(XDR *, rpcb_stat_byvers);
#elif __STDC__ 
extern  bool_t xdr_rpcb_stat_byvers(XDR *, rpcb_stat_byvers);
#else /* Old Style C */ 
bool_t xdr_rpcb_stat_byvers();
#endif /* Old Style C */ 


/*
 * We don't define netbuf in RPCL, since it would contain structure member
 * names that would conflict with the definition of struct netbuf in
 * <tiuser.h>.  Instead we merely declare the XDR routine xdr_netbuf() here,
 * and implement it ourselves in rpc/rpcb_prot.c.
 */
#ifdef __cplusplus
extern "C" bool_t xdr_netbuf(XDR *, struct netbuf *);

#else /* __STDC__ */
extern bool_t xdr_netbuf(XDR *, struct netbuf *);

#endif

#define RPCBVERS_3 RPCBVERS
#define RPCBVERS_4 RPCBVERS4

#define _PATH_RPCBINDSOCK "/var/run/rpcbind.sock"

#else /* ndef _KERNEL */
#ifdef __cplusplus
extern "C" {
#endif

/*
 * A mapping of (program, version, network ID) to address
 */
struct rpcb {
 rpcprog_t r_prog; /* program number */
 rpcvers_t r_vers; /* version number */
 char *r_netid; /* network id */
 char *r_addr; /* universal address */
 char *r_owner; /* owner of the mapping */
};
typedef struct rpcb RPCB;

/*
 * A list of mappings
 */
struct rpcblist {
 RPCB rpcb_map;
 struct rpcblist *rpcb_next;
};
typedef struct rpcblist RPCBLIST;
typedef struct rpcblist *rpcblist_ptr;

/*
 * Remote calls arguments
 */
struct rpcb_rmtcallargs {
 rpcprog_t prog; /* program number */
 rpcvers_t vers; /* version number */
 rpcproc_t proc; /* procedure number */
 u_int32_t arglen; /* arg len */
 caddr_t args_ptr; /* argument */
 xdrproc_t xdr_args; /* XDR routine for argument */
};
typedef struct rpcb_rmtcallargs rpcb_rmtcallargs;

/*
 * Remote calls results
 */
struct rpcb_rmtcallres {
 char *addr_ptr; /* remote universal address */
 u_int32_t resultslen; /* results length */
 caddr_t results_ptr; /* results */
 xdrproc_t xdr_results; /* XDR routine for result */
};
typedef struct rpcb_rmtcallres rpcb_rmtcallres;

struct rpcb_entry {
 char *r_maddr;
 char *r_nc_netid;
 unsigned int r_nc_semantics;
 char *r_nc_protofmly;
 char *r_nc_proto;
};
typedef struct rpcb_entry rpcb_entry;

/*
 * A list of addresses supported by a service.
 */

struct rpcb_entry_list {
 rpcb_entry rpcb_entry_map;
 struct rpcb_entry_list *rpcb_entry_next;
};
typedef struct rpcb_entry_list rpcb_entry_list;

typedef rpcb_entry_list *rpcb_entry_list_ptr;

/*
 * rpcbind statistics
 */

#define rpcb_highproc_2 RPCBPROC_CALLIT
#define rpcb_highproc_3 RPCBPROC_TADDR2UADDR
#define rpcb_highproc_4 RPCBPROC_GETSTAT
#define RPCBSTAT_HIGHPROC 13
#define RPCBVERS_STAT 3
#define RPCBVERS_4_STAT 2
#define RPCBVERS_3_STAT 1
#define RPCBVERS_2_STAT 0

/* Link list of all the stats about getport and getaddr */

struct rpcbs_addrlist {
 rpcprog_t prog;
 rpcvers_t vers;
 int success;
 int failure;
 char *netid;
 struct rpcbs_addrlist *next;
};
typedef struct rpcbs_addrlist rpcbs_addrlist;

/* Link list of all the stats about rmtcall */

struct rpcbs_rmtcalllist {
 rpcprog_t prog;
 rpcvers_t vers;
 rpcproc_t proc;
 int success;
 int failure;
 int indirect;
 char *netid;
 struct rpcbs_rmtcalllist *next;
};
typedef struct rpcbs_rmtcalllist rpcbs_rmtcalllist;

typedef int rpcbs_proc[RPCBSTAT_HIGHPROC];

typedef rpcbs_addrlist *rpcbs_addrlist_ptr;

typedef rpcbs_rmtcalllist *rpcbs_rmtcalllist_ptr;

struct rpcb_stat {
 rpcbs_proc info;
 int setinfo;
 int unsetinfo;
 rpcbs_addrlist_ptr addrinfo;
 rpcbs_rmtcalllist_ptr rmtinfo;
};
typedef struct rpcb_stat rpcb_stat;

/*
 * One rpcb_stat structure is returned for each version of rpcbind
 * being monitored.
 */

typedef rpcb_stat rpcb_stat_byvers[RPCBVERS_STAT];

#ifdef __cplusplus
}
#endif

#endif /* ndef _KERNEL */

#define RPCBPROG ((u_int32_t)100000)
#define RPCBVERS ((u_int32_t)3)

#ifdef __cplusplus
#define RPCBPROC_SET ((u_int32_t)1)
extern "C" bool_t * rpcbproc_set_3(rpcb *, CLIENT *);
extern "C" bool_t * rpcbproc_set_3_svc(rpcb *, struct svc_req *);
#define RPCBPROC_UNSET ((u_int32_t)2)
extern "C" bool_t * rpcbproc_unset_3(rpcb *, CLIENT *);
extern "C" bool_t * rpcbproc_unset_3_svc(rpcb *, struct svc_req *);
#define RPCBPROC_GETADDR ((u_int32_t)3)
extern "C" char ** rpcbproc_getaddr_3(rpcb *, CLIENT *);
extern "C" char ** rpcbproc_getaddr_3_svc(rpcb *, struct svc_req *);
#define RPCBPROC_DUMP ((u_int32_t)4)
extern "C" rpcblist_ptr * rpcbproc_dump_3(void *, CLIENT *);
extern "C" rpcblist_ptr * rpcbproc_dump_3_svc(void *, struct svc_req *);
#define RPCBPROC_CALLIT ((u_int32_t)5)
extern "C" rpcb_rmtcallres * rpcbproc_callit_3(rpcb_rmtcallargs *, CLIENT *);
extern "C" rpcb_rmtcallres * rpcbproc_callit_3_svc(rpcb_rmtcallargs *, struct svc_req *);
#define RPCBPROC_GETTIME ((u_int32_t)6)
extern "C" u_int * rpcbproc_gettime_3(void *, CLIENT *);
extern "C" u_int * rpcbproc_gettime_3_svc(void *, struct svc_req *);
#define RPCBPROC_UADDR2TADDR ((u_int32_t)7)
extern "C" struct netbuf * rpcbproc_uaddr2taddr_3(char **, CLIENT *);
extern "C" struct netbuf * rpcbproc_uaddr2taddr_3_svc(char **, struct svc_req *);
#define RPCBPROC_TADDR2UADDR ((u_int32_t)8)
extern "C" char ** rpcbproc_taddr2uaddr_3(struct netbuf *, CLIENT *);
extern "C" char ** rpcbproc_taddr2uaddr_3_svc(struct netbuf *, struct svc_req *);

#elif __STDC__
#define RPCBPROC_SET ((u_int32_t)1)
extern  bool_t * rpcbproc_set_3(rpcb *, CLIENT *);
extern  bool_t * rpcbproc_set_3_svc(rpcb *, struct svc_req *);
#define RPCBPROC_UNSET ((u_int32_t)2)
extern  bool_t * rpcbproc_unset_3(rpcb *, CLIENT *);
extern  bool_t * rpcbproc_unset_3_svc(rpcb *, struct svc_req *);
#define RPCBPROC_GETADDR ((u_int32_t)3)
extern  char ** rpcbproc_getaddr_3(rpcb *, CLIENT *);
extern  char ** rpcbproc_getaddr_3_svc(rpcb *, struct svc_req *);
#define RPCBPROC_DUMP ((u_int32_t)4)
extern  rpcblist_ptr * rpcbproc_dump_3(void *, CLIENT *);
extern  rpcblist_ptr * rpcbproc_dump_3_svc(void *, struct svc_req *);
#define RPCBPROC_CALLIT ((u_int32_t)5)
extern  rpcb_rmtcallres * rpcbproc_callit_3(rpcb_rmtcallargs *, CLIENT *);
extern  rpcb_rmtcallres * rpcbproc_callit_3_svc(rpcb_rmtcallargs *, struct svc_req *);
#define RPCBPROC_GETTIME ((u_int32_t)6)
extern  u_int * rpcbproc_gettime_3(void *, CLIENT *);
extern  u_int * rpcbproc_gettime_3_svc(void *, struct svc_req *);
#define RPCBPROC_UADDR2TADDR ((u_int32_t)7)
extern  struct netbuf * rpcbproc_uaddr2taddr_3(char **, CLIENT *);
extern  struct netbuf * rpcbproc_uaddr2taddr_3_svc(char **, struct svc_req *);
#define RPCBPROC_TADDR2UADDR ((u_int32_t)8)
extern  char ** rpcbproc_taddr2uaddr_3(struct netbuf *, CLIENT *);
extern  char ** rpcbproc_taddr2uaddr_3_svc(struct netbuf *, struct svc_req *);

#else /* Old Style C */ 
#define RPCBPROC_SET ((u_int32_t)1)
extern  bool_t * rpcbproc_set_3();
extern  bool_t * rpcbproc_set_3_svc();
#define RPCBPROC_UNSET ((u_int32_t)2)
extern  bool_t * rpcbproc_unset_3();
extern  bool_t * rpcbproc_unset_3_svc();
#define RPCBPROC_GETADDR ((u_int32_t)3)
extern  char ** rpcbproc_getaddr_3();
extern  char ** rpcbproc_getaddr_3_svc();
#define RPCBPROC_DUMP ((u_int32_t)4)
extern  rpcblist_ptr * rpcbproc_dump_3();
extern  rpcblist_ptr * rpcbproc_dump_3_svc();
#define RPCBPROC_CALLIT ((u_int32_t)5)
extern  rpcb_rmtcallres * rpcbproc_callit_3();
extern  rpcb_rmtcallres * rpcbproc_callit_3_svc();
#define RPCBPROC_GETTIME ((u_int32_t)6)
extern  u_int * rpcbproc_gettime_3();
extern  u_int * rpcbproc_gettime_3_svc();
#define RPCBPROC_UADDR2TADDR ((u_int32_t)7)
extern  struct netbuf * rpcbproc_uaddr2taddr_3();
extern  struct netbuf * rpcbproc_uaddr2taddr_3_svc();
#define RPCBPROC_TADDR2UADDR ((u_int32_t)8)
extern  char ** rpcbproc_taddr2uaddr_3();
extern  char ** rpcbproc_taddr2uaddr_3_svc();
#endif /* Old Style C */ 
#define RPCBVERS4 ((u_int32_t)4)

#ifdef __cplusplus
extern "C" bool_t * rpcbproc_set_4(rpcb *, CLIENT *);
extern "C" bool_t * rpcbproc_set_4_svc(rpcb *, struct svc_req *);
extern "C" bool_t * rpcbproc_unset_4(rpcb *, CLIENT *);
extern "C" bool_t * rpcbproc_unset_4_svc(rpcb *, struct svc_req *);
extern "C" char ** rpcbproc_getaddr_4(rpcb *, CLIENT *);
extern "C" char ** rpcbproc_getaddr_4_svc(rpcb *, struct svc_req *);
extern "C" rpcblist_ptr * rpcbproc_dump_4(void *, CLIENT *);
extern "C" rpcblist_ptr * rpcbproc_dump_4_svc(void *, struct svc_req *);
#define RPCBPROC_BCAST ((u_int32_t)RPCBPROC_CALLIT)
extern "C" rpcb_rmtcallres * rpcbproc_bcast_4(rpcb_rmtcallargs *, CLIENT *);
extern "C" rpcb_rmtcallres * rpcbproc_bcast_4_svc(rpcb_rmtcallargs *, struct svc_req *);
extern "C" u_int * rpcbproc_gettime_4(void *, CLIENT *);
extern "C" u_int * rpcbproc_gettime_4_svc(void *, struct svc_req *);
extern "C" struct netbuf * rpcbproc_uaddr2taddr_4(char **, CLIENT *);
extern "C" struct netbuf * rpcbproc_uaddr2taddr_4_svc(char **, struct svc_req *);
extern "C" char ** rpcbproc_taddr2uaddr_4(struct netbuf *, CLIENT *);
extern "C" char ** rpcbproc_taddr2uaddr_4_svc(struct netbuf *, struct svc_req *);
#define RPCBPROC_GETVERSADDR ((u_int32_t)9)
extern "C" char ** rpcbproc_getversaddr_4(rpcb *, CLIENT *);
extern "C" char ** rpcbproc_getversaddr_4_svc(rpcb *, struct svc_req *);
#define RPCBPROC_INDIRECT ((u_int32_t)10)
extern "C" rpcb_rmtcallres * rpcbproc_indirect_4(rpcb_rmtcallargs *, CLIENT *);
extern "C" rpcb_rmtcallres * rpcbproc_indirect_4_svc(rpcb_rmtcallargs *, struct svc_req *);
#define RPCBPROC_GETADDRLIST ((u_int32_t)11)
extern "C" rpcb_entry_list_ptr * rpcbproc_getaddrlist_4(rpcb *, CLIENT *);
extern "C" rpcb_entry_list_ptr * rpcbproc_getaddrlist_4_svc(rpcb *, struct svc_req *);
#define RPCBPROC_GETSTAT ((u_int32_t)12)
extern "C" rpcb_stat * rpcbproc_getstat_4(void *, CLIENT *);
extern "C" rpcb_stat * rpcbproc_getstat_4_svc(void *, struct svc_req *);

#elif __STDC__
extern  bool_t * rpcbproc_set_4(rpcb *, CLIENT *);
extern  bool_t * rpcbproc_set_4_svc(rpcb *, struct svc_req *);
extern  bool_t * rpcbproc_unset_4(rpcb *, CLIENT *);
extern  bool_t * rpcbproc_unset_4_svc(rpcb *, struct svc_req *);
extern  char ** rpcbproc_getaddr_4(rpcb *, CLIENT *);
extern  char ** rpcbproc_getaddr_4_svc(rpcb *, struct svc_req *);
extern  rpcblist_ptr * rpcbproc_dump_4(void *, CLIENT *);
extern  rpcblist_ptr * rpcbproc_dump_4_svc(void *, struct svc_req *);
#define RPCBPROC_BCAST ((u_int32_t)RPCBPROC_CALLIT)
extern  rpcb_rmtcallres * rpcbproc_bcast_4(rpcb_rmtcallargs *, CLIENT *);
extern  rpcb_rmtcallres * rpcbproc_bcast_4_svc(rpcb_rmtcallargs *, struct svc_req *);
extern  u_int * rpcbproc_gettime_4(void *, CLIENT *);
extern  u_int * rpcbproc_gettime_4_svc(void *, struct svc_req *);
extern  struct netbuf * rpcbproc_uaddr2taddr_4(char **, CLIENT *);
extern  struct netbuf * rpcbproc_uaddr2taddr_4_svc(char **, struct svc_req *);
extern  char ** rpcbproc_taddr2uaddr_4(struct netbuf *, CLIENT *);
extern  char ** rpcbproc_taddr2uaddr_4_svc(struct netbuf *, struct svc_req *);
#define RPCBPROC_GETVERSADDR ((u_int32_t)9)
extern  char ** rpcbproc_getversaddr_4(rpcb *, CLIENT *);
extern  char ** rpcbproc_getversaddr_4_svc(rpcb *, struct svc_req *);
#define RPCBPROC_INDIRECT ((u_int32_t)10)
extern  rpcb_rmtcallres * rpcbproc_indirect_4(rpcb_rmtcallargs *, CLIENT *);
extern  rpcb_rmtcallres * rpcbproc_indirect_4_svc(rpcb_rmtcallargs *, struct svc_req *);
#define RPCBPROC_GETADDRLIST ((u_int32_t)11)
extern  rpcb_entry_list_ptr * rpcbproc_getaddrlist_4(rpcb *, CLIENT *);
extern  rpcb_entry_list_ptr * rpcbproc_getaddrlist_4_svc(rpcb *, struct svc_req *);
#define RPCBPROC_GETSTAT ((u_int32_t)12)
extern  rpcb_stat * rpcbproc_getstat_4(void *, CLIENT *);
extern  rpcb_stat * rpcbproc_getstat_4_svc(void *, struct svc_req *);

#else /* Old Style C */ 
extern  bool_t * rpcbproc_set_4();
extern  bool_t * rpcbproc_set_4_svc();
extern  bool_t * rpcbproc_unset_4();
extern  bool_t * rpcbproc_unset_4_svc();
extern  char ** rpcbproc_getaddr_4();
extern  char ** rpcbproc_getaddr_4_svc();
extern  rpcblist_ptr * rpcbproc_dump_4();
extern  rpcblist_ptr * rpcbproc_dump_4_svc();
#define RPCBPROC_BCAST ((u_int32_t)RPCBPROC_CALLIT)
extern  rpcb_rmtcallres * rpcbproc_bcast_4();
extern  rpcb_rmtcallres * rpcbproc_bcast_4_svc();
extern  u_int * rpcbproc_gettime_4();
extern  u_int * rpcbproc_gettime_4_svc();
extern  struct netbuf * rpcbproc_uaddr2taddr_4();
extern  struct netbuf * rpcbproc_uaddr2taddr_4_svc();
extern  char ** rpcbproc_taddr2uaddr_4();
extern  char ** rpcbproc_taddr2uaddr_4_svc();
#define RPCBPROC_GETVERSADDR ((u_int32_t)9)
extern  char ** rpcbproc_getversaddr_4();
extern  char ** rpcbproc_getversaddr_4_svc();
#define RPCBPROC_INDIRECT ((u_int32_t)10)
extern  rpcb_rmtcallres * rpcbproc_indirect_4();
extern  rpcb_rmtcallres * rpcbproc_indirect_4_svc();
#define RPCBPROC_GETADDRLIST ((u_int32_t)11)
extern  rpcb_entry_list_ptr * rpcbproc_getaddrlist_4();
extern  rpcb_entry_list_ptr * rpcbproc_getaddrlist_4_svc();
#define RPCBPROC_GETSTAT ((u_int32_t)12)
extern  rpcb_stat * rpcbproc_getstat_4();
extern  rpcb_stat * rpcbproc_getstat_4_svc();
#endif /* Old Style C */ 

#endif /* !_RPCB_PROT_H_RPCGEN */
