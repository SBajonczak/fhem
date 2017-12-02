/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.2210 from the
 * contents of Interface.xs. Do not edit this file, edit Interface.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "lib/IO/Interface.xs"
/* Interface.xs: part of LibIO-Interface-Perl             */
/* Copyright 2014 Lincoln D. Stein                        */
/* Licensed under Perl Artistic License 2.0               */
/* Please see LICENSE and README.md for more information. */

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include <stdio.h>
#include <string.h>

/* socket definitions */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

/* location of IFF_* constants */
#include <net/if.h>

/* location of getifaddrs() definition */
#ifdef USE_GETIFADDRS
#include <ifaddrs.h>

#ifdef  HAVE_SOCKADDR_DL_STRUCT
#include <net/if_dl.h>
#endif

#endif

#ifndef SIOCGIFCONF
#include <sys/sockio.h>
#endif

#ifdef OSIOCGIFCONF
#define MY_SIOCGIFCONF OSIOCGIFCONF
#else
#define MY_SIOCGIFCONF SIOCGIFCONF
#endif

#ifdef PerlIO
typedef PerlIO * InputStream;
#else
#define PERLIO_IS_STDIO 1
typedef FILE * InputStream;
#define PerlIO_fileno(f) fileno(f)
#endif

#if !defined(__USE_BSD)
  #if defined(__linux__)
     typedef int IOCTL_CMD_T;
     #define __USE_BSD
  #elif defined(__APPLE__)
     typedef unsigned long IOCTL_CMD_T;
     #define __USE_BSD
  #else
     typedef int IOCTL_CMD_T;
  #endif
#else
  typedef unsigned long IOCTL_CMD_T;
#endif

/* HP-UX, Solaris */
#if !defined(ifr_mtu) && defined(ifr_metric)
#define ifr_mtu ifr_metric 
#endif 

static double
constant_IFF_N(char *name, int len, int arg)
{
    errno = 0;
    if (5 + 1 >= len ) {
	errno = EINVAL;
	return 0;
    }
    switch (name[5 + 1]) {
    case 'A':
	if (strEQ(name + 5, "OARP")) {	/* IFF_N removed */
#ifdef IFF_NOARP
	    return IFF_NOARP;
#else
	    goto not_there;
#endif
	}
    case 'T':
	if (strEQ(name + 5, "OTRAILERS")) {	/* IFF_N removed */
#ifdef IFF_NOTRAILERS
	    return IFF_NOTRAILERS;
#else
	    goto not_there;
#endif
	}
    }
    errno = EINVAL;
    return 0;

not_there:
    errno = ENOENT;
    return 0;
}

static double
constant_IFF_PO(char *name, int len, int arg)
{
    errno = 0;
    switch (name[6 + 0]) {
    case 'I':
	if (strEQ(name + 6, "INTOPOINT")) {	/* IFF_PO removed */
#ifdef IFF_POINTOPOINT
	    return IFF_POINTOPOINT;
#else
	    goto not_there;
#endif
	}
    case 'R':
	if (strEQ(name + 6, "RTSEL")) {	/* IFF_PO removed */
#ifdef IFF_PORTSEL
	    return IFF_PORTSEL;
#else
	    goto not_there;
#endif
	}
    }
    errno = EINVAL;
    return 0;

not_there:
    errno = ENOENT;
    return 0;
}

static double
constant_IFF_P(char *name, int len, int arg)
{
    errno = 0;
    switch (name[5 + 0]) {
    case 'O':
	return constant_IFF_PO(name, len, arg);
    case 'R':
	if (strEQ(name + 5, "ROMISC")) {	/* IFF_P removed */
#ifdef IFF_PROMISC
	    return IFF_PROMISC;
#else
	    goto not_there;
#endif
	}
    }
    errno = EINVAL;
    return 0;

not_there:
    errno = ENOENT;
    return 0;
}

static double
constant_IFF_A(char *name, int len, int arg)
{
    errno = 0;
    switch (name[5 + 0]) {
    case 'L':
	if (strEQ(name + 5, "LLMULTI")) {	/* IFF_A removed */
#ifdef IFF_ALLMULTI
	    return IFF_ALLMULTI;
#else
	    goto not_there;
#endif
	}
    case 'U':
	if (strEQ(name + 5, "UTOMEDIA")) {	/* IFF_A removed */
#ifdef IFF_AUTOMEDIA
	    return IFF_AUTOMEDIA;
#else
	    goto not_there;
#endif
	}
    }
    errno = EINVAL;
    return 0;

not_there:
    errno = ENOENT;
    return 0;
}

static double
constant_IFF_M(char *name, int len, int arg)
{
    errno = 0;
    switch (name[5 + 0]) {
    case 'A':
	if (strEQ(name + 5, "ASTER")) {	/* IFF_M removed */
#ifdef IFF_MASTER
	    return IFF_MASTER;
#else
	    goto not_there;
#endif
	}
    case 'U':
	if (strEQ(name + 5, "ULTICAST")) {	/* IFF_M removed */
#ifdef IFF_MULTICAST
	    return IFF_MULTICAST;
#else
	    goto not_there;
#endif
	}
    }
    errno = EINVAL;
    return 0;

not_there:
    errno = ENOENT;
    return 0;
}

static double
constant_IFF(char *name, int len, int arg)
{
    errno = 0;
    if (3 + 1 >= len ) {
	errno = EINVAL;
	return 0;
    }
    switch (name[3 + 1]) {
    case 'A':
	if (!strnEQ(name + 3,"_", 1))
	    break;
	return constant_IFF_A(name, len, arg);
    case 'B':
	if (strEQ(name + 3, "_BROADCAST")) {	/* IFF removed */
#ifdef IFF_BROADCAST
	    return IFF_BROADCAST;
#else
	    goto not_there;
#endif
	}
    case 'D':
	if (strEQ(name + 3, "_DEBUG")) {	/* IFF removed */
#ifdef IFF_DEBUG
	    return IFF_DEBUG;
#else
	    goto not_there;
#endif
	}
    case 'L':
	if (strEQ(name + 3, "_LOOPBACK")) {	/* IFF removed */
#ifdef IFF_LOOPBACK
	    return IFF_LOOPBACK;
#else
	    goto not_there;
#endif
	}
    case 'M':
	if (!strnEQ(name + 3,"_", 1))
	    break;
	return constant_IFF_M(name, len, arg);
    case 'N':
	if (!strnEQ(name + 3,"_", 1))
	    break;
	return constant_IFF_N(name, len, arg);
    case 'P':
	if (!strnEQ(name + 3,"_", 1))
	    break;
	return constant_IFF_P(name, len, arg);
    case 'R':
	if (strEQ(name + 3, "_RUNNING")) {	/* IFF removed */
#ifdef IFF_RUNNING
	    return IFF_RUNNING;
#else
	    goto not_there;
#endif
	}
    case 'S':
	if (strEQ(name + 3, "_SLAVE")) {	/* IFF removed */
#ifdef IFF_SLAVE
	    return IFF_SLAVE;
#else
	    goto not_there;
#endif
	}
    case 'U':
	if (strEQ(name + 3, "_UP")) {	/* IFF removed */
#ifdef IFF_UP
	    return IFF_UP;
#else
	    goto not_there;
#endif
	}
    }
    errno = EINVAL;
    return 0;

not_there:
    errno = ENOENT;
    return 0;
}

static double
constant_I(char *name, int len, int arg)
{
    errno = 0;
    if (1 + 1 >= len ) {
	errno = EINVAL;
	return 0;
    }
    switch (name[1 + 1]) {
    case 'F':
	if (!strnEQ(name + 1,"F", 1))
	    break;
	return constant_IFF(name, len, arg);
    case 'H':
	if (strEQ(name + 1, "FHWADDRLEN")) {	/* I removed */
#ifdef IFHWADDRLEN
	    return IFHWADDRLEN;
#else
	    goto not_there;
#endif
	}
    case 'N':
	if (strEQ(name + 1, "FNAMSIZ")) {	/* I removed */
#ifdef IFNAMSIZ
	    return IFNAMSIZ;
#else
	    goto not_there;
#endif
	}
    }
    errno = EINVAL;
    return 0;

not_there:
    errno = ENOENT;
    return 0;
}

static double
constant(char *name, int len, int arg)
{
    errno = 0;
    switch (name[0 + 0]) {
    case 'I':
	return constant_I(name, len, arg);
    }
    errno = EINVAL;
    return 0;

not_there:
    errno = ENOENT;
    return 0;
}

int Ioctl (InputStream sock, IOCTL_CMD_T operation,void* result) {
  int fd = PerlIO_fileno(sock);
  return ioctl(fd,operation,result) == 0;
}

#ifdef IFHWADDRLEN
char* parse_hwaddr (char *string, struct sockaddr* hwaddr) {
  int          len,i,consumed;
  unsigned int converted;
  char*        s;
  s = string;
  len = strlen(s);
  for (i = 0; i < IFHWADDRLEN && len > 0; i++) {
    if (sscanf(s,"%x%n",&converted,&consumed) <= 0)
      break;
    hwaddr->sa_data[i] = converted;
    s += consumed + 1;
    len -= consumed + 1;
  }
  if (i != IFHWADDRLEN)
    return NULL;
  else 
    return string;
}

/* No checking for string buffer length. Caller must ensure at least
   3*4 + 3 + 1 = 16 bytes long */
char* format_hwaddr (char *string, struct sockaddr* hwaddr) {
  int i,len;
  char *s;
  s = string;
  s[0] = '\0';
  for (i = 0; i < IFHWADDRLEN; i++) {
    if (i < IFHWADDRLEN-1)
      len = sprintf(s,"%02x:",(unsigned char)hwaddr->sa_data[i]);
    else
      len = sprintf(s,"%02x",(unsigned char)hwaddr->sa_data[i]);
    s += len;
  }
  return string;
}
#endif

#line 405 "lib/IO/Interface.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)	S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage		S_croak_xs_usage
#endif

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#line 457 "lib/IO/Interface.c"

XS(XS_IO__Interface_constant); /* prototype to pass -Wmissing-prototypes */
XS(XS_IO__Interface_constant)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "sv, arg");
    {
#line 400 "lib/IO/Interface.xs"
	STRLEN		len;
#line 472 "lib/IO/Interface.c"
	SV *	sv = ST(0);
	char *	s = SvPV(sv, len);
	int	arg = (int)SvIV(ST(1));
	double	RETVAL;
	dXSTARG;
#line 407 "lib/IO/Interface.xs"
	RETVAL = constant(s,len,arg);
#line 480 "lib/IO/Interface.c"
	XSprePUSH; PUSHn((double)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_IO__Interface_if_addr); /* prototype to pass -Wmissing-prototypes */
XS(XS_IO__Interface_if_addr)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 2)
       croak_xs_usage(cv,  "sock, name, ...");
    {
	InputStream	sock = IoIFP(sv_2io(ST(0)));
	char*	name = (char *)SvPV_nolen(ST(1));
#line 417 "lib/IO/Interface.xs"
     STRLEN        len;
     IOCTL_CMD_T   operation;
     struct ifreq  ifr;
     char*         newaddr;
#line 505 "lib/IO/Interface.c"
	char *	RETVAL;
	dXSTARG;
#line 422 "lib/IO/Interface.xs"
   {
#if !(defined(HAS_IOCTL) && defined(SIOCGIFADDR))
     XSRETURN_UNDEF;
#else
     if (strncmp(name,"any",3) == 0) {
       RETVAL = "0.0.0.0";
     } else {
       bzero((void*)&ifr,sizeof(struct ifreq));
       strncpy(ifr.ifr_name,name,IFNAMSIZ-1);
       ifr.ifr_addr.sa_family = AF_INET;
       if (items > 2) {
	 newaddr = SvPV(ST(2),len);
	 if ( inet_aton(newaddr,&((struct sockaddr_in*)&ifr.ifr_addr)->sin_addr) == 0 ) 
	   croak("Invalid inet address");
#if defined(SIOCSIFADDR)
	 operation = SIOCSIFADDR;
#else
	 croak("Cannot set interface address on this platform");
#endif
       } else {
	 operation = SIOCGIFADDR;
       }
       if (!Ioctl(sock,operation,&ifr)) XSRETURN_UNDEF;
       if (ifr.ifr_addr.sa_family != AF_INET) croak ("Address is not in the AF_INET family.\n");
       RETVAL = inet_ntoa(((struct sockaddr_in*) &ifr.ifr_addr)->sin_addr);
     }
#endif
   }
#line 537 "lib/IO/Interface.c"
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS(XS_IO__Interface_if_broadcast); /* prototype to pass -Wmissing-prototypes */
XS(XS_IO__Interface_if_broadcast)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 2)
       croak_xs_usage(cv,  "sock, name, ...");
    {
	InputStream	sock = IoIFP(sv_2io(ST(0)));
	char*	name = (char *)SvPV_nolen(ST(1));
#line 459 "lib/IO/Interface.xs"
     STRLEN        len;
     IOCTL_CMD_T   operation;
     struct ifreq  ifr;
     char*         newaddr;
#line 562 "lib/IO/Interface.c"
	char *	RETVAL;
	dXSTARG;
#line 464 "lib/IO/Interface.xs"
   {
#if !(defined(HAS_IOCTL) && defined(SIOCGIFBRDADDR))
     XSRETURN_UNDEF;
#else
     bzero((void*)&ifr,sizeof(struct ifreq));
     strncpy(ifr.ifr_name,name,IFNAMSIZ-1);
     ifr.ifr_addr.sa_family = AF_INET;
     if (items > 2) {
       newaddr = SvPV(ST(2),len);
       if ( inet_aton(newaddr,&((struct sockaddr_in*)&ifr.ifr_addr)->sin_addr) == 0 ) 
	 croak("Invalid inet address");
#if defined(SIOCSIFBRDADDR)
         operation = SIOCSIFBRDADDR;
#else
         croak("Cannot set broadcast address on this platform");
#endif 
     } else {
	  operation = SIOCGIFBRDADDR;
     }
     if (!Ioctl(sock,operation,&ifr)) XSRETURN_UNDEF;
     if (ifr.ifr_addr.sa_family != AF_INET) croak ("Address is not in the AF_INET family.\n");
     RETVAL = inet_ntoa(((struct sockaddr_in*) &ifr.ifr_addr)->sin_addr);
#endif
   }
#line 590 "lib/IO/Interface.c"
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS(XS_IO__Interface_if_netmask); /* prototype to pass -Wmissing-prototypes */
XS(XS_IO__Interface_if_netmask)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 2)
       croak_xs_usage(cv,  "sock, name, ...");
    {
	InputStream	sock = IoIFP(sv_2io(ST(0)));
	char*	name = (char *)SvPV_nolen(ST(1));
#line 497 "lib/IO/Interface.xs"
     STRLEN         len;
     IOCTL_CMD_T    operation;
     struct ifreq   ifr;
     char*          newaddr;
#line 615 "lib/IO/Interface.c"
	char *	RETVAL;
	dXSTARG;
#line 502 "lib/IO/Interface.xs"
   {
#if !(defined(HAS_IOCTL) && defined(SIOCGIFNETMASK))
     XSRETURN_UNDEF;
#else
     bzero((void*)&ifr,sizeof(struct ifreq));
     strncpy(ifr.ifr_name,name,IFNAMSIZ-1);
     ifr.ifr_addr.sa_family = AF_INET;
     if (items > 2) {
       newaddr = SvPV(ST(2),len);
       if ( inet_aton(newaddr,&((struct sockaddr_in*)&ifr.ifr_addr)->sin_addr) == 0 ) 
	 croak("Invalid inet address");
#if defined(SIOCSIFNETMASK)
         operation = SIOCSIFNETMASK; 
#else
         croak("Cannot set netmask on this platform");
#endif
     } else {
	  operation = SIOCGIFNETMASK;
     }
     if (!Ioctl(sock,operation,&ifr)) XSRETURN_UNDEF;
#if defined(__NetBSD__) || defined(__OpenBSD__)
     ifr.ifr_addr.sa_family = AF_INET;
#endif
     if (ifr.ifr_addr.sa_family != AF_INET) croak ("Address is not in the AF_INET family.\n");
     RETVAL = inet_ntoa(((struct sockaddr_in*) &ifr.ifr_addr)->sin_addr);
#endif
   }
#line 646 "lib/IO/Interface.c"
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS(XS_IO__Interface_if_dstaddr); /* prototype to pass -Wmissing-prototypes */
XS(XS_IO__Interface_if_dstaddr)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 2)
       croak_xs_usage(cv,  "sock, name, ...");
    {
	InputStream	sock = IoIFP(sv_2io(ST(0)));
	char*	name = (char *)SvPV_nolen(ST(1));
#line 538 "lib/IO/Interface.xs"
     STRLEN         len;
     IOCTL_CMD_T    operation;
     struct ifreq   ifr;
     char*          newaddr;
#line 671 "lib/IO/Interface.c"
	char *	RETVAL;
	dXSTARG;
#line 543 "lib/IO/Interface.xs"
   {
#if !(defined(HAS_IOCTL) && defined(SIOCGIFDSTADDR))
     XSRETURN_UNDEF;
#else
     bzero((void*)&ifr,sizeof(struct ifreq));
     strncpy(ifr.ifr_name,name,IFNAMSIZ-1);
     ifr.ifr_addr.sa_family = AF_INET;
     if (items > 2) {
       newaddr = SvPV(ST(2),len);
       if ( inet_aton(newaddr,&((struct sockaddr_in*)&ifr.ifr_addr)->sin_addr) == 0 ) 
	 croak("Invalid inet address");
#if defined(SIOCSIFDSTADDR)
       operation = SIOCSIFDSTADDR;
#else
       croak("Cannot set destination address on this platform");
#endif
     } else {
       operation = SIOCGIFDSTADDR;
     }
     if (!Ioctl(sock,operation,&ifr)) XSRETURN_UNDEF;
     if (ifr.ifr_addr.sa_family != AF_INET) croak ("Address is not in the AF_INET family.\n");
     RETVAL = inet_ntoa(((struct sockaddr_in*) &ifr.ifr_addr)->sin_addr);
#endif
   }
#line 699 "lib/IO/Interface.c"
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS(XS_IO__Interface_if_hwaddr); /* prototype to pass -Wmissing-prototypes */
XS(XS_IO__Interface_if_hwaddr)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 2)
       croak_xs_usage(cv,  "sock, name, ...");
    {
	InputStream	sock = IoIFP(sv_2io(ST(0)));
	char*	name = (char *)SvPV_nolen(ST(1));
#line 576 "lib/IO/Interface.xs"
     STRLEN	    len;
     IOCTL_CMD_T    operation;
     struct ifreq   ifr;
#if (defined(USE_GETIFADDRS) && defined(HAVE_SOCKADDR_DL_STRUCT))
     struct ifaddrs *ifap, *ifa;
     struct sockaddr_dl* sdl;
     sa_family_t  family;
     char *sdlname, *haddr, *s;
     int hlen = 0;
     int i;
#endif
     char           *newaddr,hwaddr[128];
#line 732 "lib/IO/Interface.c"
	char *	RETVAL;
	dXSTARG;
#line 589 "lib/IO/Interface.xs"
   {
#if !((defined(HAS_IOCTL) && defined(SIOCGIFHWADDR)) || defined(USE_GETIFADDRS))
     XSRETURN_UNDEF;
#endif
#if (defined(USE_GETIFADDRS) && defined(HAVE_SOCKADDR_DL_STRUCT))
     getifaddrs(&ifap);

     for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
       if (strncmp(name, ifa->ifa_name, IFNAMSIZ) == 0) {
         family = ifa->ifa_addr->sa_family;
         if (family == AF_LINK) {
           sdl = (struct sockaddr_dl *) ifa->ifa_addr;
           haddr = sdl->sdl_data + sdl->sdl_nlen;
           hlen = sdl->sdl_alen;
           break;
         }
       }
     } 

     s = hwaddr; 
     s[0] = '\0';
     if (ifap != NULL) {
       for (i = 0; i < hlen; i++) {
         if (i < hlen - 1)
           len = sprintf(s,"%02x:",(unsigned char)haddr[i]);
         else
           len = sprintf(s,"%02x",(unsigned char)haddr[i]);
         s += len;
       }
     }

     freeifaddrs(ifap);

     RETVAL = hwaddr;
#elif (defined(HAS_IOCTL) && defined(SIOCGIFHWADDR))
     bzero((void*)&ifr,sizeof(struct ifreq));
     strncpy(ifr.ifr_name,name,IFNAMSIZ-1);
     ifr.ifr_hwaddr.sa_family = AF_UNSPEC;
     if (items > 2) {
       newaddr = SvPV(ST(2),len);
       if (parse_hwaddr(newaddr,&ifr.ifr_hwaddr) == NULL)
	 croak("Invalid hardware address");
#if defined(SIOCSIFHWADDR)
       operation = SIOCSIFHWADDR;
#else
       croak("Cannot set hw address on this platform");
#endif
     } else {
       operation = SIOCGIFHWADDR;
     }
     if (!Ioctl(sock,operation,&ifr)) XSRETURN_UNDEF;
     RETVAL = format_hwaddr(hwaddr,&ifr.ifr_hwaddr);
#endif
   }
#line 790 "lib/IO/Interface.c"
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS(XS_IO__Interface_if_flags); /* prototype to pass -Wmissing-prototypes */
XS(XS_IO__Interface_if_flags)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 2)
       croak_xs_usage(cv,  "sock, name, ...");
    {
	InputStream	sock = IoIFP(sv_2io(ST(0)));
	char*	name = (char *)SvPV_nolen(ST(1));
#line 653 "lib/IO/Interface.xs"
     IOCTL_CMD_T    operation;
     int            flags;
     struct ifreq   ifr;
#line 814 "lib/IO/Interface.c"
	int	RETVAL;
	dXSTARG;
#line 657 "lib/IO/Interface.xs"
   {
#if !(defined(HAS_IOCTL) && defined(SIOCGIFFLAGS))
     XSRETURN_UNDEF;
#endif
     bzero((void*)&ifr,sizeof(struct ifreq));
     strncpy(ifr.ifr_name,name,IFNAMSIZ-1);
     if (items > 2) {
       ifr.ifr_flags = SvIV(ST(2));
#if defined(SIOCSIFFLAGS)
       operation = SIOCSIFFLAGS;
#else
       croak("Cannot set flags on this platform.");
#endif
     } else {
       operation = SIOCGIFFLAGS;
     }
     if (!Ioctl(sock,operation,&ifr)) XSRETURN_UNDEF;
     RETVAL = ifr.ifr_flags;
   }
#line 837 "lib/IO/Interface.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_IO__Interface_if_mtu); /* prototype to pass -Wmissing-prototypes */
XS(XS_IO__Interface_if_mtu)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 2)
       croak_xs_usage(cv,  "sock, name, ...");
    {
	InputStream	sock = IoIFP(sv_2io(ST(0)));
	char*	name = (char *)SvPV_nolen(ST(1));
#line 685 "lib/IO/Interface.xs"
     IOCTL_CMD_T    operation;
     int            flags;
     struct ifreq   ifr;
#line 861 "lib/IO/Interface.c"
	int	RETVAL;
	dXSTARG;
#line 689 "lib/IO/Interface.xs"
   {
#if !(defined(HAS_IOCTL) && defined(SIOCGIFFLAGS))
     XSRETURN_UNDEF;
#endif
     bzero((void*)&ifr,sizeof(struct ifreq));
     strncpy(ifr.ifr_name,name,IFNAMSIZ-1);
     if (items > 2) {
       ifr.ifr_flags = SvIV(ST(2));
#if defined(SIOCSIFMTU)
       operation = SIOCSIFMTU;
#else
	 croak("Cannot set MTU on this platform.");
#endif
     } else {
       operation = SIOCGIFMTU;
     }
     if (!Ioctl(sock,operation,&ifr)) XSRETURN_UNDEF;
     RETVAL = ifr.ifr_mtu;
   }
#line 884 "lib/IO/Interface.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_IO__Interface_if_metric); /* prototype to pass -Wmissing-prototypes */
XS(XS_IO__Interface_if_metric)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 2)
       croak_xs_usage(cv,  "sock, name, ...");
    {
	InputStream	sock = IoIFP(sv_2io(ST(0)));
	char*	name = (char *)SvPV_nolen(ST(1));
#line 717 "lib/IO/Interface.xs"
     IOCTL_CMD_T    operation;
     int            flags;
     struct ifreq   ifr;
#line 908 "lib/IO/Interface.c"
	int	RETVAL;
	dXSTARG;
#line 721 "lib/IO/Interface.xs"
   {
#if !(defined(HAS_IOCTL) && defined(SIOCGIFFLAGS))
     XSRETURN_UNDEF;
#endif
     bzero((void*)&ifr,sizeof(struct ifreq));
     strncpy(ifr.ifr_name,name,IFNAMSIZ-1);
     if (items > 2) {
       ifr.ifr_flags = SvIV(ST(2));
#if defined(SIOCSIFMETRIC)
       operation = SIOCSIFMETRIC;
#else
	 croak("Cannot set metric on this platform.");
#endif
     } else {
       operation = SIOCGIFMETRIC;
     }
     if (!Ioctl(sock,operation,&ifr)) XSRETURN_UNDEF;
     RETVAL = ifr.ifr_metric;
   }
#line 931 "lib/IO/Interface.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_IO__Interface_if_index); /* prototype to pass -Wmissing-prototypes */
XS(XS_IO__Interface_if_index)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 2)
       croak_xs_usage(cv,  "sock, name, ...");
    {
	InputStream	sock = IoIFP(sv_2io(ST(0)));
	char*	name = (char *)SvPV_nolen(ST(1));
	int	RETVAL;
	dXSTARG;
#line 749 "lib/IO/Interface.xs"
   {
#ifdef __USE_BSD
     RETVAL = if_nametoindex(name);
#else
     XSRETURN_UNDEF;
#endif
   }
#line 961 "lib/IO/Interface.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_IO__Interface_if_indextoname); /* prototype to pass -Wmissing-prototypes */
XS(XS_IO__Interface_if_indextoname)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 2)
       croak_xs_usage(cv,  "sock, index, ...");
    {
	InputStream	sock = IoIFP(sv_2io(ST(0)));
	int	index = (int)SvIV(ST(1));
#line 765 "lib/IO/Interface.xs"
     char  name[IFNAMSIZ];
#line 983 "lib/IO/Interface.c"
	char *	RETVAL;
	dXSTARG;
#line 767 "lib/IO/Interface.xs"
   {
#ifdef __USE_BSD
     RETVAL = if_indextoname(index,name);
#else
    XSRETURN_UNDEF;
#endif
   }
#line 994 "lib/IO/Interface.c"
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS(XS_IO__Interface__if_list); /* prototype to pass -Wmissing-prototypes */
XS(XS_IO__Interface__if_list)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "sock");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	InputStream	sock = IoIFP(sv_2io(ST(0)));
#line 782 "lib/IO/Interface.xs"
#ifdef USE_GETIFADDRS
       struct ifaddrs *ifa_start;
       struct ifaddrs *ifa;
#else
       struct ifconf ifc;
       struct ifreq  *ifr;
       int    lastlen,len;
       char   *buf,*ptr;
#endif
#line 1025 "lib/IO/Interface.c"
#line 792 "lib/IO/Interface.xs"
#ifdef USE_GETIFADDRS
       if (getifaddrs(&ifa_start) < 0)
	 XSRETURN_EMPTY;

       for (ifa = ifa_start ; ifa ; ifa = ifa->ifa_next)
	 XPUSHs(sv_2mortal(newSVpv(ifa->ifa_name,0)));

       freeifaddrs(ifa_start);
#else
       lastlen = 0;
       len     = 10 * sizeof(struct ifreq); /* initial buffer size guess */
       for ( ; ; ) {
	 if ( (buf = safemalloc(len)) == NULL)
	   croak("Couldn't malloc buffer for ioctl: %s",strerror(errno));
	 ifc.ifc_len = len;
	 ifc.ifc_buf = buf;
	 if (ioctl(PerlIO_fileno(sock),MY_SIOCGIFCONF,&ifc) < 0) {
	   if (errno != EINVAL || lastlen != 0)
	     XSRETURN_EMPTY;
	 } else {
	   if (ifc.ifc_len == lastlen) break;  /* success, len has not changed */
	   lastlen = ifc.ifc_len;
	 }
	 len += 10 * sizeof(struct ifreq); /* increment */
	 safefree(buf);
       }

       for (ptr = buf ; ptr < buf + ifc.ifc_len ; ptr += sizeof(struct ifreq)) {
	 ifr = (struct ifreq*) ptr;
	 XPUSHs(sv_2mortal(newSVpv(ifr->ifr_name,0)));
       }
       safefree(buf);
#endif
#line 1060 "lib/IO/Interface.c"
	PUTBACK;
	return;
    }
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_IO__Interface); /* prototype to pass -Wmissing-prototypes */
XS(boot_IO__Interface)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#endif
    XS_VERSION_BOOTCHECK ;

        (void)newXSproto_portable("IO::Interface::constant", XS_IO__Interface_constant, file, "$;$");
        (void)newXSproto_portable("IO::Interface::if_addr", XS_IO__Interface_if_addr, file, "$$;$");
        (void)newXSproto_portable("IO::Interface::if_broadcast", XS_IO__Interface_if_broadcast, file, "$$;$");
        (void)newXSproto_portable("IO::Interface::if_netmask", XS_IO__Interface_if_netmask, file, "$$;$");
        (void)newXSproto_portable("IO::Interface::if_dstaddr", XS_IO__Interface_if_dstaddr, file, "$$;$");
        (void)newXSproto_portable("IO::Interface::if_hwaddr", XS_IO__Interface_if_hwaddr, file, "$$;$");
        (void)newXSproto_portable("IO::Interface::if_flags", XS_IO__Interface_if_flags, file, "$$;$");
        (void)newXSproto_portable("IO::Interface::if_mtu", XS_IO__Interface_if_mtu, file, "$$;$");
        (void)newXSproto_portable("IO::Interface::if_metric", XS_IO__Interface_if_metric, file, "$$;$");
        (void)newXSproto_portable("IO::Interface::if_index", XS_IO__Interface_if_index, file, "$$;$");
        (void)newXSproto_portable("IO::Interface::if_indextoname", XS_IO__Interface_if_indextoname, file, "$$;$");
        (void)newXSproto_portable("IO::Interface::_if_list", XS_IO__Interface__if_list, file, "$");
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}
