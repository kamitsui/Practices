 #include <stdio.h>
 #include <stdlib.h>
 #include <locale.h>
 /* This program is compile LOCALETYPE(*LOCALE)  and               */
 /* SYSIFCOPT(*IFSIO)    */
 int main(void)
 {
     wchar_t wc = (wchar_t)0x00C4;     /*  D */
     wchar_t ws[4];
     ws[0] = (wchar_t)0x00C1;        /* A   */
     ws[1] = (wchar_t)0x00C2;        /* B   */
     ws[2] = (wchar_t)0x00C3;        /* C   */
     ws[3] = (wchar_t)0x0000;
     /* The output displayed is CCSID 37  */
     printf("%lc   %ls\n\n",wc,ws);

     /* Now let's try a mixed-byte CCSID example  */
     /* You would need a device that can handle mixed bytes to  */
     /* display this correctly.                         */

     setlocale(LC_ALL,
     "/QSYS.LIB/JA_JP.LOCALE"); /* a CCSID 5026 locale */

     /* big A means an A that takes up 2 bytes on the screen   */
     /* It will look bigger than single byte A                 */

     ws[0] = (wchar_t)0x42C1;        /* big A   */
     ws[1] = (wchar_t)0x42C2;        /* big B   */
     ws[2] = (wchar_t)0x42C3;        /* big C   */
     ws[3] = (wchar_t)0x0000;
     wc = 0x42F1;                    /* big 1   */

     printf("%lc   %ls\n\n",wc,ws);

     /* The output of this printf is not shown below and it   */
     /* will differ depending on the device you display it on,*/
     /* but if you looked at the string in hex it would look  */
     /* like this:  0E42F10F404040400E42C142C242C30F          */
     /* 0E is shift out, 0F is shift in, and 42F1 is the      */
     /* big 1 in CCSID   5026  */

     printf("%lc   %.4ls\n\n",wc,ws);

     /* The output of this printf is not shown below either. */
     /* The hex would look like:                             */
     /* 0E42F10F404040400E42C10F                             */
     /* Since the precision is in bytes we only get 4 bytes  */
     /* of the string.         */

     printf("%lc   %#.2ls\n\n",wc,ws);

     /* The output of this printf is not shown below either. */
     /* The hex would look like:                             */
     /* 0E42F10F404040400E42C142C20F                         */
     /* The # means precision is in characters regardless   */
     /* of size.  So we get 2 characters of the string.      */
 }
 /*****************  Output should be similar to:  *****************


 D     ABC


 *******************************************************************/
 
