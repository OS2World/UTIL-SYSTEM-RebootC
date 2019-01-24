#define INCL_DOS
#include <os2.h>
#define DOSS		  "\\DEV\\DOS$"
#define CATEGORY_DOSSYS 0xD5 
#define FUNCTION_REBOOT 0xAB
main()
{
SHORT rc ;
HFILE hDD ;
USHORT usAction ;
rc = DosOpen ( DOSS, &hDD, &usAction,
			   0L, FILE_NORMAL,
			   FILE_OPEN, OPEN_SHARE_DENYNONE |
			   OPEN_ACCESS_READWRITE, 0L );
if (!rc)
   {
   DosDevIOCtl ( NULL,
              NULL,
              FUNCTION_REBOOT,
              CATEGORY_DOSSYS,
              hDD );

   DosClose ( hDD );
   }
return 0 ;
}
