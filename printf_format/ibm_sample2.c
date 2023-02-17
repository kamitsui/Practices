     #include <stdio.h>
     #include <stdlib.h>
     #include <locale.h>
     /* This program is compiled with LOCALETYPE(*LOCALEUCS2) and             */
     /* SYSIFCOPT(*IFSIO)                                               */
     /* We will assume the locale setting is the same as the CCSID of the */
     /* job.  We will also assume any files involved have a CCSID of      */
     /* 65535 (no convert).  This way if printf goes to the screen or     */
     /* a file the output will be the same.                               */
    int main(void)
    {
        wchar_t wc = 0x0058;     /* UNICODE X */
        wchar_t ws[4];
        setlocale(LC_ALL,
         "/QSYS.LIB/EN_US.LOCALE"); /* a CCSID 37 locale */
        ws[0] = 0x0041;        /* UNICODE A   */
        ws[1] = (wchar_t)0x0042;        /* UNICODE B   */
        ws[2] = (wchar_t)0x0043;        /* UNICODE C   */
        ws[3] = (wchar_t)0x0000;
        /* The output displayed is CCSID 37  */
        printf("%lc   %ls\n\n",wc,ws);
        printf("%lc   %.2ls\n\n",wc,ws);

        /* Now let's try a mixed-byte CCSID example  */
        /* You would need a device that can handle mixed bytes to  */
        /* display this correctly.                         */

        setlocale(LC_ALL,
        "/QSYS.LIB/JA_JP.LOCALE");/* a CCSID 5026 locale */

        /* big A means an A that takes up 2 bytes on the screen   */
        /* It will look bigger then single byte A                 */
        ws[0] = (wchar_t)0xFF21;        /* UNICODE big A   */
        ws[1] = (wchar_t)0xFF22;        /* UNICODE big B   */
        ws[2] = (wchar_t)0xFF23;        /* UNICODE big C   */
        ws[3] = (wchar_t)0x0000;
        wc = 0xff11;                    /* UNICODE big 1   */

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
        /* The # means precision is in characters reguardless   */
        /* of size.  So we get 2 characters of the string.      */
    }
 /*****************  Output should be similar to:  *****************


 X     ABC

 X     AB

 *******************************************************************/
 
