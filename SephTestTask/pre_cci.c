# 1 "c:\\users\\hanna_tarletskaya\\loadrunner-data\\scripts\\sephora - copy\\sephora_testscript\\\\combined_Sephora_TestScript_copy.c"
# 1 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h" 1
 
 












 











# 103 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"






















































		


		typedef unsigned size_t;
	
	
        
	

















	

 



















 
 
 
 
 


 
 
 
 
 
 














int     lr_start_transaction   (char * transaction_name);
int lr_start_sub_transaction          (char * transaction_name, char * trans_parent);
long lr_start_transaction_instance    (char * transaction_name, long parent_handle);
int   lr_start_cross_vuser_transaction		(char * transaction_name, char * trans_id_param); 



int     lr_end_transaction     (char * transaction_name, int status);
int lr_end_sub_transaction            (char * transaction_name, int status);
int lr_end_transaction_instance       (long transaction, int status);
int   lr_end_cross_vuser_transaction	(char * transaction_name, char * trans_id_param, int status);


 
typedef char* lr_uuid_t;
 



lr_uuid_t lr_generate_uuid();

 


int lr_generate_uuid_free(lr_uuid_t uuid);

 



int lr_generate_uuid_on_buf(lr_uuid_t buf);

   
# 273 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
int lr_start_distributed_transaction  (char * transaction_name, lr_uuid_t correlator, long timeout  );

   







int lr_end_distributed_transaction  (lr_uuid_t correlator, int status);


double lr_stop_transaction            (char * transaction_name);
double lr_stop_transaction_instance   (long parent_handle);


void lr_resume_transaction           (char * trans_name);
void lr_resume_transaction_instance  (long trans_handle);


int lr_update_transaction            (const char *trans_name);


 
void lr_wasted_time(long time);


 
int lr_set_transaction(const char *name, double duration, int status);
 
long lr_set_transaction_instance(const char *name, double duration, int status, long parent_handle);


int   lr_user_data_point                      (char *, double);
long lr_user_data_point_instance                   (char *, double, long);
 



int lr_user_data_point_ex(const char *dp_name, double value, int log_flag);
long lr_user_data_point_instance_ex(const char *dp_name, double value, long parent_handle, int log_flag);


int lr_transaction_add_info      (const char *trans_name, char *info);
int lr_transaction_instance_add_info   (long trans_handle, char *info);
int lr_dpoint_add_info           (const char *dpoint_name, char *info);
int lr_dpoint_instance_add_info        (long dpoint_handle, char *info);


double lr_get_transaction_duration       (char * trans_name);
double lr_get_trans_instance_duration    (long trans_handle);
double lr_get_transaction_think_time     (char * trans_name);
double lr_get_trans_instance_think_time  (long trans_handle);
double lr_get_transaction_wasted_time    (char * trans_name);
double lr_get_trans_instance_wasted_time (long trans_handle);
int    lr_get_transaction_status		 (char * trans_name);
int	   lr_get_trans_instance_status		 (long trans_handle);

 



int lr_set_transaction_status(int status);

 



int lr_set_transaction_status_by_name(int status, const char *trans_name);
int lr_set_transaction_instance_status(int status, long trans_handle);


typedef void* merc_timer_handle_t;
 

merc_timer_handle_t lr_start_timer();
double lr_end_timer(merc_timer_handle_t timer_handle);


 
 
 
 
 
 











 



int   lr_rendezvous  (char * rendezvous_name);
 




int   lr_rendezvous_ex (char * rendezvous_name);



 
 
 
 
 
char *lr_get_vuser_ip (void);
void   lr_whoami (int *vuser_id, char ** sgroup, int *scid);
char *	  lr_get_host_name (void);
char *	  lr_get_master_host_name (void);

 
long     lr_get_attrib_long	(char * attr_name);
char *   lr_get_attrib_string	(char * attr_name);
double   lr_get_attrib_double      (char * attr_name);

char * lr_paramarr_idx(const char * paramArrayName, unsigned int index);
char * lr_paramarr_random(const char * paramArrayName);
int    lr_paramarr_len(const char * paramArrayName);

int	lr_param_unique(const char * paramName);
int lr_param_sprintf(const char * paramName, const char * format, ...);


 
 
static void *ci_this_context = 0;






 








void lr_continue_on_error (int lr_continue);
char *   lr_decrypt (const char *EncodedString);


 
 
 
 
 
 



 







 















void   lr_abort (void);
void lr_exit(int exit_option, int exit_status);
void lr_abort_ex (unsigned long flags);

void   lr_peek_events (void);


 
 
 
 
 


void   lr_think_time (double secs);

 


void lr_force_think_time (double secs);


 
 
 
 
 



















int   lr_msg (char * fmt, ...);
int   lr_debug_message (unsigned int msg_class,
									    char * format,
										...);
# 512 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
void   lr_new_prefix (int type,
                                 char * filename,
                                 int line);
# 515 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
int   lr_log_message (char * fmt, ...);
int   lr_message (char * fmt, ...);
int   lr_error_message (char * fmt, ...);
int   lr_output_message (char * fmt, ...);
int   lr_vuser_status_message (char * fmt, ...);
int   lr_error_message_without_fileline (char * fmt, ...);
int   lr_fail_trans_with_error (char * fmt, ...);

 
 
 
 
 
# 539 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"

 
 
 
 
 





int   lr_next_row ( char * table);
int lr_advance_param ( char * param);



														  
														  

														  
														  

													      
 


char *   lr_eval_string (char * str);
int   lr_eval_string_ext (const char *in_str,
                                     unsigned long const in_len,
                                     char ** const out_str,
                                     unsigned long * const out_len,
                                     unsigned long const options,
                                     const char *file,
								     long const line);
# 573 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
void   lr_eval_string_ext_free (char * * pstr);

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int lr_param_increment (char * dst_name,
                              char * src_name);
# 596 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"













											  
											  

											  
											  
											  

int	  lr_save_var (char *              param_val,
							  unsigned long const param_val_len,
							  unsigned long const options,
							  char *			  param_name);
# 620 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
int   lr_save_string (const char * param_val, const char * param_name);



int   lr_set_custom_error_message (const char * param_val, ...);

int   lr_remove_custom_error_message ();


int   lr_free_parameter (const char * param_name);
int   lr_save_int (const int param_val, const char * param_name);
int   lr_save_timestamp (const char * tmstampParam, ...);
int   lr_save_param_regexp (const char *bufferToScan, unsigned int bufSize, ...);

int   lr_convert_double_to_integer (const char *source_param_name, const char * target_param_name);
int   lr_convert_double_to_double (const char *source_param_name, const char *format_string, const char * target_param_name);

 
 
 
 
 
 
# 699 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
void   lr_save_datetime (const char *format, int offset, const char *name);









 











 
 
 
 
 






 



char * lr_error_context_get_entry (char * key);

 



long   lr_error_context_get_error_id (void);


 
 
 

int lr_table_get_rows_num (char * param_name);

int lr_table_get_cols_num (char * param_name);

char * lr_table_get_cell_by_col_index (char * param_name, int row, int col);

char * lr_table_get_cell_by_col_name (char * param_name, int row, const char* col_name);

int lr_table_get_column_name_by_index (char * param_name, int col, 
											char * * const col_name,
											size_t * col_name_len);
# 760 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"

int lr_table_get_column_name_by_index_free (char * col_name);

 
 
 
 
# 775 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
int   lr_zip (const char* param1, const char* param2);
int   lr_unzip (const char* param1, const char* param2);

 
 
 
 
 
 
 
 

 
 
 
 
 
 
int   lr_param_substit (char * file,
                                   int const line,
                                   char * in_str,
                                   size_t const in_len,
                                   char * * const out_str,
                                   size_t * const out_len);
# 799 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
void   lr_param_substit_free (char * * pstr);


 
# 811 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"





char *   lrfnc_eval_string (char * str,
                                      char * file_name,
                                      long const line_num);
# 819 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"


int   lrfnc_save_string ( const char * param_val,
                                     const char * param_name,
                                     const char * file_name,
                                     long const line_num);
# 825 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"

int   lrfnc_free_parameter (const char * param_name );







typedef struct _lr_timestamp_param
{
	int iDigits;
}lr_timestamp_param;

extern const lr_timestamp_param default_timestamp_param;

int   lrfnc_save_timestamp (const char * param_name, const lr_timestamp_param* time_param);

int lr_save_searched_string(char * buffer, long buf_size, unsigned int occurrence,
			    char * search_string, int offset, unsigned int param_val_len, 
			    char * param_name);

 
char *   lr_string (char * str);

 
# 926 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"

int   lr_save_value (char * param_val,
                                unsigned long const param_val_len,
                                unsigned long const options,
                                char * param_name,
                                char * file_name,
                                long const line_num);
# 933 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"


 
 
 
 
 











int   lr_printf (char * fmt, ...);
 
int   lr_set_debug_message (unsigned int msg_class,
                                       unsigned int swtch);
# 955 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
unsigned int   lr_get_debug_message (void);


 
 
 
 
 

void   lr_double_think_time ( double secs);
void   lr_usleep (long);


 
 
 
 
 
 




int *   lr_localtime (long offset);


int   lr_send_port (long port);


# 1031 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"



struct _lr_declare_identifier{
	char signature[24];
	char value[128];
};

int   lr_pt_abort (void);

void vuser_declaration (void);






# 1060 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"


# 1072 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
















 
 
 
 
 







int    _lr_declare_transaction   (char * transaction_name);


 
 
 
 
 







int   _lr_declare_rendezvous  (char * rendezvous_name);

 
 
 
 
 


typedef int PVCI;






typedef int VTCERR;









PVCI   vtc_connect(char * servername, int portnum, int options);
VTCERR   vtc_disconnect(PVCI pvci);
VTCERR   vtc_get_last_error(PVCI pvci);
VTCERR   vtc_query_column(PVCI pvci, char * columnName, int columnIndex, char * *outvalue);
VTCERR   vtc_query_row(PVCI pvci, int rowIndex, char * **outcolumns, char * **outvalues);
VTCERR   vtc_send_message(PVCI pvci, char * column, char * message, unsigned short *outRc);
VTCERR   vtc_send_if_unique(PVCI pvci, char * column, char * message, unsigned short *outRc);
VTCERR   vtc_send_row1(PVCI pvci, char * columnNames, char * messages, char * delimiter, unsigned char sendflag, unsigned short *outUpdates);
VTCERR   vtc_update_message(PVCI pvci, char * column, int index , char * message, unsigned short *outRc);
VTCERR   vtc_update_message_ifequals(PVCI pvci, char * columnName, int index,	char * message, char * ifmessage, unsigned short 	*outRc);
VTCERR   vtc_update_row1(PVCI pvci, char * columnNames, int index , char * messages, char * delimiter, unsigned short *outUpdates);
VTCERR   vtc_retrieve_message(PVCI pvci, char * column, char * *outvalue);
VTCERR   vtc_retrieve_messages1(PVCI pvci, char * columnNames, char * delimiter, char * **outvalues);
VTCERR   vtc_retrieve_row(PVCI pvci, char * **outcolumns, char * **outvalues);
VTCERR   vtc_rotate_message(PVCI pvci, char * column, char * *outvalue, unsigned char sendflag);
VTCERR   vtc_rotate_messages1(PVCI pvci, char * columnNames, char * delimiter, char * **outvalues, unsigned char sendflag);
VTCERR   vtc_rotate_row(PVCI pvci, char * **outcolumns, char * **outvalues, unsigned char sendflag);
VTCERR   vtc_increment(PVCI pvci, char * column, int index , int incrValue, int *outValue);
VTCERR   vtc_clear_message(PVCI pvci, char * column, int index , unsigned short *outRc);
VTCERR   vtc_clear_column(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_ensure_index(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_drop_index(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_clear_row(PVCI pvci, int rowIndex, unsigned short *outRc);
VTCERR   vtc_create_column(PVCI pvci, char * column,unsigned short *outRc);
VTCERR   vtc_column_size(PVCI pvci, char * column, int *size);
void   vtc_free(char * msg);
void   vtc_free_list(char * *msglist);

VTCERR   lrvtc_connect(char * servername, int portnum, int options);
VTCERR   lrvtc_disconnect();
VTCERR   lrvtc_query_column(char * columnName, int columnIndex);
VTCERR   lrvtc_query_row(int columnIndex);
VTCERR   lrvtc_send_message(char * columnName, char * message);
VTCERR   lrvtc_send_if_unique(char * columnName, char * message);
VTCERR   lrvtc_send_row1(char * columnNames, char * messages, char * delimiter, unsigned char sendflag);
VTCERR   lrvtc_update_message(char * columnName, int index , char * message);
VTCERR   lrvtc_update_message_ifequals(char * columnName, int index, char * message, char * ifmessage);
VTCERR   lrvtc_update_row1(char * columnNames, int index , char * messages, char * delimiter);
VTCERR   lrvtc_retrieve_message(char * columnName);
VTCERR   lrvtc_retrieve_messages1(char * columnNames, char * delimiter);
VTCERR   lrvtc_retrieve_row();
VTCERR   lrvtc_rotate_message(char * columnName, unsigned char sendflag);
VTCERR   lrvtc_rotate_messages1(char * columnNames, char * delimiter, unsigned char sendflag);
VTCERR   lrvtc_rotate_row(unsigned char sendflag);
VTCERR   lrvtc_increment(char * columnName, int index , int incrValue);
VTCERR   lrvtc_noop();
VTCERR   lrvtc_clear_message(char * columnName, int index);
VTCERR   lrvtc_clear_column(char * columnName); 
VTCERR   lrvtc_ensure_index(char * columnName); 
VTCERR   lrvtc_drop_index(char * columnName); 
VTCERR   lrvtc_clear_row(int rowIndex);
VTCERR   lrvtc_create_column(char * columnName);
VTCERR   lrvtc_column_size(char * columnName);



 
 
 
 
 

 
int lr_enable_ip_spoofing();
int lr_disable_ip_spoofing();


 




int lr_convert_string_encoding(char * sourceString, char * fromEncoding, char * toEncoding, char * paramName);
int lr_read_file(const char *filename, const char *outputParam, int continueOnError);


 
int lr_db_connect (char * pFirstArg, ...);
int lr_db_disconnect (char * pFirstArg,	...);
int lr_db_executeSQLStatement (char * pFirstArg, ...);
int lr_db_dataset_action(char * pFirstArg, ...);
int lr_checkpoint(char * pFirstArg,	...);
int lr_db_getvalue(char * pFirstArg, ...);







 
 



















# 1 "c:\\users\\hanna_tarletskaya\\loadrunner-data\\scripts\\sephora - copy\\sephora_testscript\\\\combined_Sephora_TestScript_copy.c" 2

# 1 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/SharedParameter.h" 1



 
 
 
 
# 100 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/SharedParameter.h"






typedef int PVCI2;






typedef int VTCERR2;


 
 
 

 
extern PVCI2    vtc_connect(char *servername, int portnum, int options);
extern VTCERR2  vtc_disconnect(PVCI2 pvci);
extern VTCERR2  vtc_get_last_error(PVCI2 pvci);

 
extern VTCERR2  vtc_query_column(PVCI2 pvci, char *columnName, int columnIndex, char **outvalue);
extern VTCERR2  vtc_query_row(PVCI2 pvci, int columnIndex, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_send_message(PVCI2 pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_if_unique(PVCI2 pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_row1(PVCI2 pvci, char *columnNames, char *messages, char *delimiter,  unsigned char sendflag, unsigned short *outUpdates);
extern VTCERR2  vtc_update_message(PVCI2 pvci, char *column, int index , char *message, unsigned short *outRc);
extern VTCERR2  vtc_update_message_ifequals(PVCI2 pvci, char	*columnName, int index,	char *message, char	*ifmessage,	unsigned short 	*outRc);
extern VTCERR2  vtc_update_row1(PVCI2 pvci, char *columnNames, int index , char *messages, char *delimiter, unsigned short *outUpdates);
extern VTCERR2  vtc_retrieve_message(PVCI2 pvci, char *column, char **outvalue);
extern VTCERR2  vtc_retrieve_messages1(PVCI2 pvci, char *columnNames, char *delimiter, char ***outvalues);
extern VTCERR2  vtc_retrieve_row(PVCI2 pvci, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_rotate_message(PVCI2 pvci, char *column, char **outvalue, unsigned char sendflag);
extern VTCERR2  vtc_rotate_messages1(PVCI2 pvci, char *columnNames, char *delimiter, char ***outvalues, unsigned char sendflag);
extern VTCERR2  vtc_rotate_row(PVCI2 pvci, char ***outcolumns, char ***outvalues, unsigned char sendflag);
extern VTCERR2	vtc_increment(PVCI2 pvci, char *column, int index , int incrValue, int *outValue);
extern VTCERR2  vtc_clear_message(PVCI2 pvci, char *column, int index , unsigned short *outRc);
extern VTCERR2  vtc_clear_column(PVCI2 pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_clear_row(PVCI2 pvci, int rowIndex, unsigned short *outRc);

extern VTCERR2  vtc_create_column(PVCI2 pvci, char *column,unsigned short *outRc);
extern VTCERR2  vtc_column_size(PVCI2 pvci, char *column, int *size);
extern VTCERR2  vtc_ensure_index(PVCI2 pvci, char *column, unsigned short *outRc);
extern VTCERR2  vtc_drop_index(PVCI2 pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_noop(PVCI2 pvci);

 
extern void vtc_free(char *msg);
extern void vtc_free_list(char **msglist);

 


 




 




















 




 
 
 

extern VTCERR2  lrvtc_connect(char *servername, int portnum, int options);
extern VTCERR2  lrvtc_disconnect();
extern VTCERR2  lrvtc_query_column(char *columnName, int columnIndex);
extern VTCERR2  lrvtc_query_row(int columnIndex);
extern VTCERR2  lrvtc_send_message(char *columnName, char *message);
extern VTCERR2  lrvtc_send_if_unique(char *columnName, char *message);
extern VTCERR2  lrvtc_send_row1(char *columnNames, char *messages, char *delimiter,  unsigned char sendflag);
extern VTCERR2  lrvtc_update_message(char *columnName, int index , char *message);
extern VTCERR2  lrvtc_update_message_ifequals(char *columnName, int index, char 	*message, char *ifmessage);
extern VTCERR2  lrvtc_update_row1(char *columnNames, int index , char *messages, char *delimiter);
extern VTCERR2  lrvtc_retrieve_message(char *columnName);
extern VTCERR2  lrvtc_retrieve_messages1(char *columnNames, char *delimiter);
extern VTCERR2  lrvtc_retrieve_row();
extern VTCERR2  lrvtc_rotate_message(char *columnName, unsigned char sendflag);
extern VTCERR2  lrvtc_rotate_messages1(char *columnNames, char *delimiter, unsigned char sendflag);
extern VTCERR2  lrvtc_rotate_row(unsigned char sendflag);
extern VTCERR2  lrvtc_increment(char *columnName, int index , int incrValue);
extern VTCERR2  lrvtc_clear_message(char *columnName, int index);
extern VTCERR2  lrvtc_clear_column(char *columnName);
extern VTCERR2  lrvtc_clear_row(int rowIndex);
extern VTCERR2  lrvtc_create_column(char *columnName);
extern VTCERR2  lrvtc_column_size(char *columnName);
extern VTCERR2  lrvtc_ensure_index(char *columnName);
extern VTCERR2  lrvtc_drop_index(char *columnName);

extern VTCERR2  lrvtc_noop();

 
 
 

                               


 
 
 





















# 2 "c:\\users\\hanna_tarletskaya\\loadrunner-data\\scripts\\sephora - copy\\sephora_testscript\\\\combined_Sephora_TestScript_copy.c" 2

# 1 "globals.h" 1

# 1 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/web_api.h" 1







# 1 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/as_web.h" 1



























































 




 



 











 





















 
 
 

  int
	web_add_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_add_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
	
  int
	web_add_auto_header(
		const char *		mpszHeader,
		const char *		mpszValue);

  int
	web_add_header(
		const char *		mpszHeader,
		const char *		mpszValue);
  int
	web_add_cookie(
		const char *		mpszCookie);
  int
	web_cleanup_auto_headers(void);
  int
	web_cleanup_cookies(void);
  int
	web_concurrent_end(
		const char * const	mpszReserved,
										 
		...								 
	);
  int
	web_concurrent_start(
		const char * const	mpszConcurrentGroupName,
										 
										 
		...								 
										 
	);
  int
	web_create_html_param(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim);
  int
	web_create_html_param_ex(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim,
		const char *		mpszNum);
  int
	web_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	spdy_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_disable_keep_alive(void);
  int
	web_enable_keep_alive(void);
  int
	web_find(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_get_int_property(
		const int			miHttpInfoType);
  int
	web_image(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_image_check(
		const char *		mpszName,
		...);
  int
	web_java_check(
		const char *		mpszName,
		...);
  int
	web_link(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

	
  int
	web_global_verification(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
  int
	web_reg_find(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
				
  int
	web_reg_save_param(
		const char *		mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 

  int
	web_convert_param(
		const char * 		mpszParamName, 
										 
		...);							 
										 
										 


										 

										 
  int
	web_remove_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
				
  int
	web_remove_auto_header(
		const char *		mpszHeaderName,
		...);							 
										 



  int
	web_remove_cookie(
		const char *		mpszCookie);

  int
	web_save_header(
		const char *		mpszType,	 
		const char *		mpszName);	 
  int
	web_set_certificate(
		const char *		mpszIndex);
  int
	web_set_certificate_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_set_connections_limit(
		const char *		mpszLimit);
  int
	web_set_max_html_param_len(
		const char *		mpszLen);
  int
	web_set_max_retries(
		const char *		mpszMaxRetries);
  int
	web_set_proxy(
		const char *		mpszProxyHost);
  int
	web_set_pac(
		const char *		mpszPacUrl);
  int
	web_set_proxy_bypass(
		const char *		mpszBypass);
  int
	web_set_secure_proxy(
		const char *		mpszProxyHost);
  int
	web_set_sockets_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue
	);
  int
	web_set_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue,
		...								 
	);
  int
	web_set_timeout(
		const char *		mpszWhat,
		const char *		mpszTimeout);
  int
	web_set_user(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);

  int
	web_sjis_to_euc_param(
		const char *		mpszParamName,
										 
		const char *		mpszParamValSjis);
										 

  int
	web_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	spdy_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_submit_form(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	spdy_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_set_proxy_bypass_local(
		const char * mpszNoLocal
		);

  int 
	web_cache_cleanup(void);

  int
	web_create_html_query(
		const char* mpszStartQuery,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_create_radio_button_param(
		const char *NameFiled,
		const char *NameAndVal,
		const char *ParamName
		);

  int
	web_convert_from_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										
  int
	web_convert_to_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_ex(
		const char * mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_xpath(
		const char * mpszParamName,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_json(
		const char * mpszParamName,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_regexp(
		 const char * mpszParamName,
		 ...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_run(
		const char * mpszCode,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_reset(void);

  int
	web_convert_date_param(
		const char * 		mpszParamName,
		...);










# 769 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/as_web.h"


# 782 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/as_web.h"



























# 820 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/as_web.h"

 
 
 


  int
	FormSubmit(
		const char *		mpszFormName,
		...);
  int
	InitWebVuser(void);
  int
	SetUser(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);
  int
	TerminateWebVuser(void);
  int
	URL(
		const char *		mpszUrlName);
























# 888 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/as_web.h"


  int
	web_rest(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 

  int
web_stream_open(
	const char *		mpszArg1,
	...
);
  int
	web_stream_wait(
		const char *		mpszArg1,
		...
	);

  int
	web_stream_close(
		const char *		mpszArg1,
		...
	);

  int
web_stream_play(
	const char *		mpszArg1,
	...
	);

  int
web_stream_pause(
	const char *		mpszArg1,
	...
	);

  int
web_stream_seek(
	const char *		mpszArg1,
	...
	);

  int
web_stream_get_param_int(
	const char*			mpszStreamID,
	const int			miStateType
	);

  double
web_stream_get_param_double(
	const char*			mpszStreamID,
	const int			miStateType
	);

  int
web_stream_get_param_string(
	const char*			mpszStreamID,
	const int			miStateType,
	const char*			mpszParameterName
	);

  int
web_stream_set_param_int(
	const char*			mpszStreamID,
	const int			miStateType,
	const int			miStateValue
	);

  int
web_stream_set_param_double(
	const char*			mpszStreamID,
	const int			miStateType,
	const double		mdfStateValue
	);

 
 
 






# 9 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/web_api.h" 2

















 







 














  int
	web_reg_add_cookie(
		const char *		mpszCookie,
		...);							 
										 

  int
	web_report_data_point(
		const char *		mpszEventType,
		const char *		mpszEventName,
		const char *		mpszDataPointName,
		const char *		mpszLAST);	 
										 
										 
										 

  int
	web_text_link(
		const char *		mpszStepName,
		...);

  int
	web_element(
		const char *		mpszStepName,
		...);

  int
	web_image_link(
		const char *		mpszStepName,
		...);

  int
	web_static_image(
		const char *		mpszStepName,
		...);

  int
	web_image_submit(
		const char *		mpszStepName,
		...);

  int
	web_button(
		const char *		mpszStepName,
		...);

  int
	web_edit_field(
		const char *		mpszStepName,
		...);

  int
	web_radio_group(
		const char *		mpszStepName,
		...);

  int
	web_check_box(
		const char *		mpszStepName,
		...);

  int
	web_list(
		const char *		mpszStepName,
		...);

  int
	web_text_area(
		const char *		mpszStepName,
		...);

  int
	web_map_area(
		const char *		mpszStepName,
		...);

  int
	web_eval_java_script(
		const char *		mpszStepName,
		...);

  int
	web_reg_dialog(
		const char *		mpszArg1,
		...);

  int
	web_reg_cross_step_download(
		const char *		mpszArg1,
		...);

  int
	web_browser(
		const char *		mpszStepName,
		...);

  int
	web_control(
		const char *		mpszStepName,
		...);

  int
	web_set_rts_key(
		const char *		mpszArg1,
		...);

  int
	web_save_param_length(
		const char * 		mpszParamName,
		...);

  int
	web_save_timestamp_param(
		const char * 		mpszParamName,
		...);

  int
	web_load_cache(
		const char *		mpszStepName,
		...);							 
										 

  int
	web_dump_cache(
		const char *		mpszStepName,
		...);							 
										 
										 

  int
	web_reg_find_in_log(
		const char *		mpszArg1,
		...);							 
										 
										 

  int
	web_get_sockets_info(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 

  int
	web_add_cookie_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

  int
	web_hook_java_script(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

 
 
 
 
 
 
 
 
 
 
 
 
  int
	web_reg_async_attributes(
		const char *		mpszArg,
		...
	);

 
 
 
 
 
 
  int
	web_sync(
		 const char *		mpszArg1,
		 ...
	);

 
 
 
 
  int
	web_stop_async(
		const char *		mpszArg1,
		...
	);

 
 
 
 
 

 
 
 

typedef enum WEB_ASYNC_CB_RC_ENUM_T
{
	WEB_ASYNC_CB_RC_OK,				 

	WEB_ASYNC_CB_RC_ABORT_ASYNC_NOT_ERROR,
	WEB_ASYNC_CB_RC_ABORT_ASYNC_ERROR,
										 
										 
										 
										 
	WEB_ASYNC_CB_RC_ENUM_COUNT
} WEB_ASYNC_CB_RC_ENUM;

 
 
 

typedef enum WEB_CONVERS_CB_CALL_REASON_ENUM_T
{
	WEB_CONVERS_CB_CALL_REASON_BUFFER_RECEIVED,
	WEB_CONVERS_CB_CALL_REASON_END_OF_TASK,

	WEB_CONVERS_CB_CALL_REASON_ENUM_COUNT
} WEB_CONVERS_CB_CALL_REASON_ENUM;

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

typedef
int														 
	(*RequestCB_t)();

typedef
int														 
	(*ResponseBodyBufferCB_t)(
		  const char *		aLastBufferStr,
		  int				aLastBufferLen,
		  const char *		aAccumulatedStr,
		  int				aAccumulatedLen,
		  int				aHttpStatusCode);

typedef
int														 
	(*ResponseCB_t)(
		  const char *		aResponseHeadersStr,
		  int				aResponseHeadersLen,
		  const char *		aResponseBodyStr,
		  int				aResponseBodyLen,
		  int				aHttpStatusCode);

typedef
int														 
	(*ResponseHeadersCB_t)(
		  int				aHttpStatusCode,
		  const char *		aAccumulatedHeadersStr,
		  int				aAccumulatedHeadersLen);



 
 
 

typedef enum WEB_CONVERS_UTIL_RC_ENUM_T
{
	WEB_CONVERS_UTIL_RC_OK,
	WEB_CONVERS_UTIL_RC_CONVERS_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_TASK_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_UNAVIALABLE,
	WEB_CONVERS_UTIL_RC_INVALID_ARGUMENT,

	WEB_CONVERS_UTIL_RC_ENUM_COUNT
} WEB_CONVERS_UTIL_RC_ENUM;

 
 
 

  int					 
	web_util_set_request_url(
		  const char *		aUrlStr);

  int					 
	web_util_set_request_body(
		  const char *		aRequestBodyStr);

  int					 
	web_util_set_formatted_request_body(
		  const char *		aRequestBodyStr);


 
 
 
 
 

 
 
 
 
 

 
 
 
 
 
 
 
 

 
 
  int
web_websocket_connect(
		 const char *	mpszArg1,
		 ...
		 );


 
 
 
 
 																						
  int
web_websocket_send(
	   const char *		mpszArg1,
		...
	   );

 
 
 
 
 
 
  int
web_websocket_close(
		const char *	mpszArg1,
		...
		);

 
typedef
void														
(*OnOpen_t)(
			  const char* connectionID,  
			  const char * responseHeader,  
			  int length  
);

typedef
void														
(*OnMessage_t)(
	  const char* connectionID,  
	  int isbinary,  
	  const char * data,  
	  int length  
	);

typedef
void														
(*OnError_t)(
	  const char* connectionID,  
	  const char * message,  
	  int length  
	);

typedef
void														
(*OnClose_t)(
	  const char* connectionID,  
	  int isClosedByClient,  
	  int code,  
	  const char* reason,  
	  int length  
	 );
 
 
 
 
 





# 2 "globals.h" 2

# 1 "lrw_custom_body.h" 1
 




# 3 "globals.h" 2



 
#
# 3 "c:\\users\\hanna_tarletskaya\\loadrunner-data\\scripts\\sephora - copy\\sephora_testscript\\\\combined_Sephora_TestScript_copy.c" 2

# 1 "vuser_init.c" 1
vuser_init()
{

	web_cleanup_cookies();
	return 0;
}
# 4 "c:\\users\\hanna_tarletskaya\\loadrunner-data\\scripts\\sephora - copy\\sephora_testscript\\\\combined_Sephora_TestScript_copy.c" 2

# 1 "MyAction.c" 1
MyAction()
{
	 
	int r;
	 
	char* IEVersion;
	
	char* wordForCategory;
	 
	
	int itemsTotal;
	int itemsOnPage;
	int numberOfItemsToAdd;
	
	char* wordForSearch;
		
	int itemNumber;
	int itemSelected;
	
	int itemsInCart;
	
	char* str;
		int sz;
	
	 
# 43 "MyAction.c"
	
	 
# 63 "MyAction.c"
	
 
	 
	r = rand() %100 + 1;
	 
	if(r<=25){
		lr_param_sprintf("browserVersion", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36");
	}
	else if((r>25)&&(r<=30)){
		lr_param_sprintf("browserVersion", "Mozilla/5.0 (Windows; U; MSIE 7.0; Windows NT 6.0; en-US)");
	}
	else if((r>30)&&(r<=40)){
		lr_param_sprintf("browserVersion", "Mozilla/5.0 (compatible; MSIE 8.0; Windows NT 6.1; Trident/4.0; GTB7.4; InfoPath.2; SV1; .NET CLR 3.3.69573; WOW64; en-US)");
	}
	else if((r>40)&&(r<=60)){
		lr_param_sprintf("browserVersion", "Mozilla/5.0 (Windows; U; MSIE 9.0; WIndows NT 9.0; en-US)");
	}
	else if((r>60)&&(r<=70)){
		lr_param_sprintf("browserVersion", "Mozilla/5.0 (compatible; MSIE 10.0; Windows NT 7.0; InfoPath.3; .NET CLR 3.1.40767; Trident/6.0; en-IN)");
	}
	else{
		lr_param_sprintf("browserVersion", "Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; AS; rv:11.0) like Gecko");
	}
	

	lr_start_transaction("001_OpenHomePage");
		 
	
		 
		web_add_header("User-Agent", "{browserVersion}");
		web_custom_request("001_OpenHomePage",
			"URL={homeUrl}/",
			"Method=GET",
			"Resource=0",
			"RecContentType=text/html",
			"Referer=",
			"Snapshot=t001.inf",
			"Mode=HTTP",
			"LAST");

	lr_end_transaction("001_OpenHomePage", 2);

 
	 
	
	r = rand()%10;
	if(r < 5){
		lr_start_transaction("002_OpenCategory");
	
			 
			r = rand()%10;
			if (r<5){
				wordForCategory = "fragrance";
			}
			else{
				wordForCategory = "makeup-tools";
			}
			lr_save_string(wordForCategory, "wordForCategory");
			
			 
			if(strcmp(wordForCategory, "makeup-tools")==0){
				r = rand()%5;
			} else if (strcmp(wordForCategory, "fragrance")==0){
				r = rand()%3;								 
			}
			lr_param_sprintf("category_path", "$.categories.sub_categories[%d].seo_path", r);  
			
			web_set_max_html_param_len("100000");
			web_reg_save_param("jsonForCategory",
				"LB=<script id=\"searchResult\" type=\"text/json\" seph-pagedata>",
				"RB=</script>",
				"LAST");
			
			web_add_header("User-Agent", "{browserVersion}");
			web_custom_request("002_OpenCategory",
				"URL={homeUrl}/{wordForCategory}",
				"Method=GET",
				"Resource=0",
				"RecContentType=text/html",
				"Referer={homeUrl}",
				"Snapshot=t002.inf",
				"Mode=HTTP",
				"LAST");
			
			lr_eval_json("Buffer={jsonForCategory}",
				  "JsonObject=json_obj_category",
						 "LAST");
			lr_json_get_values("JsonObject=json_obj_category",
							   "ValueParam=linkForSubcategory",
							   "QueryString={category_path}",
							   "LAST");
		
		lr_end_transaction("002_OpenCategory", 2);
		

		
		 

		lr_start_transaction("003_OpenSubcategory");
	
			str = lr_eval_string("{linkForSubcategory}");
			sz	= strlen(str);
			memmove(str, str + 1, sz - 1);
			str[sz - 1] = 0;
			lr_save_string(str, "linkForSubcategory");
	
			web_reg_save_param("jsonForItems",
				"LB=",
				"RB=",
				"Search=Body",
				"LAST");
			
			web_add_header("User-Agent", "{browserVersion}");
			web_custom_request("003_OpenSubcategory",
				"URL={homeUrl}/rest/products/?categoryName={linkForSubcategory}&include_categories=true&include_refinements=true",
				"Method=GET",
				"Resource=1",
				"RecContentType=application/json",
				"Snapshot=t003.inf",
				"LAST");
			
			lr_eval_json("Buffer={jsonForItems}",
					 "JsonObject=json_obj_items",
					 "LAST");
			lr_json_get_values("JsonObject=json_obj_items",
						   "ValueParam=numberOfItemsTotal",
						   "QueryString=$.total_products",
						   "LAST");
			lr_json_get_values("JsonObject=json_obj_items",
						   "ValueParam=numberOfItemsOnPage",
						   "QueryString=$.page_size",
						   "LAST");
					
			itemsTotal = atoi(lr_eval_string("{numberOfItemsTotal}"));
			itemsOnPage = atoi(lr_eval_string("{numberOfItemsOnPage}"));
			if(itemsTotal > 0){
				if(itemsOnPage < itemsTotal){
					itemNumber = itemsOnPage;
				} else{
					itemNumber = itemsTotal;
				}
				itemSelected = rand()% itemNumber;
				lr_param_sprintf("item_path", "$.products[%d].product_url", itemSelected);
				lr_param_sprintf("item_id", "$.products[%d].id", itemSelected);
				lr_param_sprintf("sku_id", "$.products[%d].derived_sku.sku_number", itemSelected);
				lr_json_get_values("JsonObject=json_obj_items",
						   "ValueParam=itemLink",
						   "QueryString={item_path}",
						   "LAST");
				lr_json_get_values("JsonObject=json_obj_items",
						   "ValueParam=itemID",
						   "QueryString={item_id}",
						   "LAST");
				lr_json_get_values("JsonObject=json_obj_items",
						   "ValueParam=skuID",
						   "QueryString={sku_id}",
						   "LAST");
			}
			
		lr_end_transaction("003_OpenSubcategory", 2);
	}
	else{
		lr_start_transaction("004_Search");
			
				r = rand()%100 + 1;
				if(r<=30){
					wordForSearch = "Fragrance";
				}
				else if((r>30)&&(r<=50)){
					wordForSearch = "Lipstick";
				}
				else if((r>50)&&(r<=70)){
					wordForSearch = "Color";
				}
				else if((r>70)&&(r<=80)){
					wordForSearch = "Shampoo";
				}
				else if((r>80)&&(r<=90)){
					wordForSearch = "Skin";
				}
				else if((r>90)&&(r<=95)){
					wordForSearch = "Eye";
				}
				else{
					wordForSearch = "Face";
				}
				lr_param_sprintf("wordForSearch", wordForSearch);
				
				web_set_max_html_param_len("100000");
				web_reg_save_param("jsonForSearch",
					"LB=<script id=\"searchResult\" type=\"text/json\" seph-pagedata>",
					"RB=</script>",
					"LAST");
				
				web_add_header("User-Agent", "{browserVersion}");
				web_custom_request("004_Search",
					"URL={homeUrl}/search/search.jsp?keyword={wordForSearch}&mode=all",
					"Method=GET",
					"Resource=0",
					"RecContentType=text/html",
					"Referer={homeUrl}",
					"Snapshot=t004.inf",
					"Mode=HTTP",
					"LAST");
				
			lr_eval_json("Buffer={jsonForSearch}",
					 "JsonObject=json_obj_search", "LAST");
			lr_json_get_values("JsonObject=json_obj_search",
						   "ValueParam=numberOfItemsSearch",
						   "QueryString=$.products.total_products",
						   "LAST");
			lr_json_get_values("JsonObject=json_obj_search",
						   "ValueParam=numberOfItemsOnPageSearch",
						   "QueryString=$.products.page_size",
						   "LAST");
					
			itemsTotal = atoi(lr_eval_string("{numberOfItemsSearch}"));
			itemsOnPage = atoi(lr_eval_string("{numberOfItemsOnPageSearch}"));
			if(itemsTotal > 0){
				if(itemsOnPage < itemsTotal){
					itemNumber = itemsOnPage;
				} else{
					itemNumber = itemsTotal;
				}
				itemSelected = rand()% itemNumber;
				lr_param_sprintf("item_path", "$.products.products[%d].product_url", itemSelected);
				lr_param_sprintf("item_id", "$.products.products[%d].id", itemSelected);
				lr_param_sprintf("sku_id", "$.products.products[%d].derived_sku.sku_number", itemSelected);
				lr_json_get_values("JsonObject=json_obj_search",
						   "ValueParam=itemLink",
						   "QueryString={item_path}",
						   "LAST");
				lr_json_get_values("JsonObject=json_obj_search",
						   "ValueParam=itemID",
						   "QueryString={item_id}",
						   "LAST");
				lr_json_get_values("JsonObject=json_obj_search",
						   "ValueParam=skuID",
						   "QueryString={sku_id}",
						   "LAST");
			}
			
		lr_end_transaction("004_Search", 2);
	}
	
	
	
	
	
	lr_start_transaction("005_OpenItem");
	
		web_add_header("User-Agent", "{browserVersion}");
		web_custom_request("005_OpenItem",
		"URL={homeUrl}/{itemLink}",
		"Method=GET",
		"Resource=0",
		"RecContentType=text/html",
		"Snapshot=t005.inf",
		"Mode=HTTP",
		"LAST");

	lr_end_transaction("005_OpenItem", 2);

	
	
	
	
 
numberOfItemsToAdd = atoi(lr_eval_string("{numberOfItemsToAdd}"));
for(r = 0; r < numberOfItemsToAdd; r++){
	
		lr_start_transaction("006_AddItemToCart");
	
			web_add_header("User-Agent", "{browserVersion}");
			web_custom_request("006_AddItemToCart",
				"URL={homeUrl}/rest/user/cart",
				"Method=POST",
				"Resource=0",
				"RecContentType=application/json",
				"Snapshot=t006.inf",
				"Mode=HTTP",
				"EncType=application/x-www-form-urlencoded; charset=UTF-8",
				"Body=%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.itemsMap.{skuID}=1&validate_order=false&is_row=false&scope=inline",
				"LAST");
			
		lr_end_transaction("006_AddItemToCart", 2);
	 }




	
	lr_start_transaction("007_CheckBasket");

		web_reg_save_param("jsonForBasket",
			"LB=",
			"RB=",
			"Search=Body",
			"LAST");
	
		web_add_header("User-Agent", "{browserVersion}");
		web_custom_request("007_CheckBasket",
			"URL={homeUrl}/api/shopping-cart/basket",
			"Method=GET",
			"Resource=1",
			"RecContentType=application/json",
			"Snapshot=t007.inf",
			"LAST");
		
		lr_eval_json("Buffer={jsonForBasket}",
				 "JsonObject=json_obj_basket", 
				 "LAST");
		lr_json_get_values("JsonObject=json_obj_basket",
					   "ValueParam=numberOfItemsInCart",
					   "QueryString=$.itemCount",
					   "LAST");
					   
		itemsInCart = atoi(lr_eval_string("{numberOfItemsInCart}"));

		if(itemsInCart==numberOfItemsToAdd){
			lr_end_transaction("007_CheckBasket", 0);
		}
		else{
			lr_end_transaction("007_CheckBasket", 1);
		}

	
	return 0;
}
# 5 "c:\\users\\hanna_tarletskaya\\loadrunner-data\\scripts\\sephora - copy\\sephora_testscript\\\\combined_Sephora_TestScript_copy.c" 2

# 1 "OpenHomePage.c" 1
OpenHomePage()
{
 
	int r;
	
	 
	r = rand() %100 + 1;
	
	if(r<=25){
		lr_param_sprintf("browserVersion", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36");
	}
	else if((r>25)&&(r<=30)){
		lr_param_sprintf("browserVersion", "Mozilla/5.0 (Windows; U; MSIE 7.0; Windows NT 6.0; en-US)");
	}
	else if((r>30)&&(r<=40)){
		lr_param_sprintf("browserVersion", "Mozilla/5.0 (compatible; MSIE 8.0; Windows NT 6.1; Trident/4.0; GTB7.4; InfoPath.2; SV1; .NET CLR 3.3.69573; WOW64; en-US)");
	}
	else if((r>40)&&(r<=60)){
		lr_param_sprintf("browserVersion", "Mozilla/5.0 (Windows; U; MSIE 9.0; WIndows NT 9.0; en-US)");
	}
	else if((r>60)&&(r<=70)){
		lr_param_sprintf("browserVersion", "Mozilla/5.0 (compatible; MSIE 10.0; Windows NT 7.0; InfoPath.3; .NET CLR 3.1.40767; Trident/6.0; en-IN)");
	}
	else{
		lr_param_sprintf("browserVersion", "Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; AS; rv:11.0) like Gecko");
	}
	
	
	web_cleanup_cookies();
	
	 
	web_add_header("User-Agent", "{browserVersion}");
	
	web_custom_request("OpenHomePage",
		"URL={homeUrl}/",
		"Method=GET",		
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTTP", 
		"LAST");
	
	return 0;
}
# 6 "c:\\users\\hanna_tarletskaya\\loadrunner-data\\scripts\\sephora - copy\\sephora_testscript\\\\combined_Sephora_TestScript_copy.c" 2

# 1 "OpenCategory.c" 1
OpenCategory()
{
	char* wordForCategory;
	int number;
	
	lr_param_sprintf("typeOfRequest", "Category");
	
	number = rand()%10;
	 
	if (number< 5){
		wordForCategory = "fragrance";
	}
	else{
		wordForCategory = "makeup-tools";
	}
		
	lr_save_string(wordForCategory, "wordForCategory");	
	 
	
	 
	if(strcmp(wordForCategory, "makeup-tools")== 0){
		number = rand()%5;
	} else if (strcmp(wordForCategory, "fragrance")==0){
		number = rand()%3;								 
	}

	lr_param_sprintf("category_path", "$.categories.sub_categories[%d].seo_path", number);  
	
	
	 
	 
	
	 
	 
	
	web_set_max_html_param_len("100000");
	
	web_reg_save_param(
		"jsonPart",
		"LB=<script id=\"searchResult\" type=\"text/json\" seph-pagedata>",
		"RB=</script>",
		"LAST");

	web_add_header("User-Agent", "{browserVersion}");
	
	web_custom_request("OpenCategory", 
		"URL={homeUrl}/{wordForCategory}",
		"Method=GET",
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={homeUrl}", 
		"Snapshot=t2.inf", 
		"Mode=HTTP",  
		"LAST");
	
	lr_eval_json("Buffer={jsonPart}",
                 "JsonObject=json_obj", "LAST");
	
	lr_json_get_values("JsonObject=json_obj",
                       "ValueParam=linkForSubcategory",
                       "QueryString={category_path}",
                       "LAST");
	lr_json_stringify("JsonObject=json_obj",
	                  "OutputParam=result",
                       "LAST");
	
	return 0;
}
# 7 "c:\\users\\hanna_tarletskaya\\loadrunner-data\\scripts\\sephora - copy\\sephora_testscript\\\\combined_Sephora_TestScript_copy.c" 2

# 1 "Search.c" 1
Search()
{
	 
	int r;
	
	r = rand() %100 + 1;
	
	if(r<=30){
		lr_param_sprintf("wordForSearch", "Fragrance");
	}
	else if((r>30)&&(r<=50)){
		lr_param_sprintf("wordForSearch", "Lipstick");
	}
	else if((r>50)&&(r<=70)){
		lr_param_sprintf("wordForSearch", "Color");
	}
	else if((r>70)&&(r<=80)){
		lr_param_sprintf("wordForSearch", "Shampoo");
	}
	else if((r>80)&&(r<=90)){
		lr_param_sprintf("wordForSearch", "Skin");
	}
	else if((r>90)&&(r<=95)){
		lr_param_sprintf("wordForSearch", "Eye");
	}
	else{
		lr_param_sprintf("wordForSearch", "Face");
	}
	

	web_add_header("User-Agent", "{browserVersion}");
	
	web_custom_request("Search",
		"URL={homeUrl}shop/search?keyword={wordForSearch}",
 
		"Method=GET",
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={homeUrl}", 
		"Snapshot=t40.inf", 
		"Mode=HTTP", 
		"LAST");
	
	return 0;
}
# 8 "c:\\users\\hanna_tarletskaya\\loadrunner-data\\scripts\\sephora - copy\\sephora_testscript\\\\combined_Sephora_TestScript_copy.c" 2

# 1 "OpenSubcategory.c" 1
OpenSubcategory()
{

	 
	if(strcmp("", "Search")){
		int itemsTotal;
		int itemsOnPage;
		
		int itemNumber;
		int itemSelected;
		
		 
		char* str;	
		int sz;
		str = lr_eval_string("{linkForSubcategory}");  
		sz	= strlen(str);							   
		memmove(str, str + 1, sz - 1); 				   
		str[sz - 1] = 0;
		lr_save_string(str, "linkForSubcategory");
		 
		
		web_reg_save_param("jsonForItems",
			"LB=",
			"RB=",
			"Search=Body",
			"LAST");
		
		web_add_header("User-Agent", "{browserVersion}");
	
		web_custom_request("OpenSubcategory", 
			"URL={homeUrl}/rest/products/?categoryName={linkForSubcategory}&include_categories=true&include_refinements=true", 
			"Method=GET", 
			"Resource=1", 
			"RecContentType=application/json", 
			"Snapshot=t11.inf", 
			"LAST");
		
		lr_eval_json("Buffer={jsonForItems}",
                 "JsonObject=json_obj", "LAST");
		
		lr_json_get_values("JsonObject=json_obj",
                       "ValueParam=numberOfItems",
                       "QueryString=$.total_products",
                       "LAST");
		
		lr_json_get_values("JsonObject=json_obj",
                       "ValueParam=numberOfItemsOnPage",
                       "QueryString=$.page_size",
                       "LAST");
				
		itemsTotal = atoi(lr_eval_string("{numberOfItems}"));
		itemsOnPage = atoi(lr_eval_string("{numberOfItemsOnPage}"));
		if(itemsTotal > 0){
			if(itemsOnPage < itemsTotal){
				itemNumber = itemsOnPage;
			} else{
				itemNumber = itemsTotal;
			}
			itemSelected = rand()% itemNumber;
			lr_param_sprintf("item_path", "$.products[%d].product_url", itemSelected);
			lr_param_sprintf("item_id", "$.products[%d].id", itemSelected);
			lr_param_sprintf("sku_id", "$.products[%d].derived_sku.sku_number", itemSelected);
			lr_json_get_values("JsonObject=json_obj",
                       "ValueParam=itemLink",
                       "QueryString={item_path}",
                       "LAST");
			lr_json_get_values("JsonObject=json_obj",
                       "ValueParam=itemID",
                       "QueryString={item_id}",
                       "LAST");
			lr_json_get_values("JsonObject=json_obj",
                       "ValueParam=skuID",
                       "QueryString={sku_id}",
                       "LAST");
		}
	}
	
	return 0;
	
 
# 1589 "OpenSubcategory.c"
}
# 9 "c:\\users\\hanna_tarletskaya\\loadrunner-data\\scripts\\sephora - copy\\sephora_testscript\\\\combined_Sephora_TestScript_copy.c" 2

# 1 "OpenItem.c" 1
OpenItem()
{
	
	web_custom_request("OpenItem", 
		 
		"URL={homeUrl}{itemLink}", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		 
		"Snapshot=t693.inf", 
		"Mode=HTTP", 
		"LAST");
	
	return 0;
}
# 10 "c:\\users\\hanna_tarletskaya\\loadrunner-data\\scripts\\sephora - copy\\sephora_testscript\\\\combined_Sephora_TestScript_copy.c" 2

# 1 "AddItemToCart.c" 1
AddItemToCart()
{

 
# 29 "AddItemToCart.c"
 
	web_custom_request("add_to_cart", 
		"URL=http://triggeredmail.appspot.com/api/track/add_to_cart", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://www.sephora.com/sole-di-positano-P417168?skuId=1913672&icid2=products%20grid:p417168", 
		"Snapshot=t788.inf", 
		"Mode=HTTP", 
		"Body=data=eyJldmVudCI6ICJhZGRfdG9fY2FydCIsInByb3BlcnRpZXMiOiB7Im9zIjogIldpbmRvd3MiLCJicm93c2VyIjogIk1vemlsbGEiLCJtcF9saWIiOiAid2ViIiwiZGlzdGluY3RfaWQiOiAiMTVjZDQ3YTk4MmI4YWMtMDYxMWJiZWRmZjcyOTM0LTRiNWY0NTFiLTFmYTQwMC0xNWNkNDdhOTgyY2I0NCIsInByb2R1Y3RzIjogWwogICAgeyJpZCI6ICJQNDE3MTY4In0KXSwidXJsIjogImh0dHA6Ly93d3cuc2VwaG9yYS5jb20vc29sZS1kaS1wb3NpdGFuby1QNDE3MTY4P3NrdUlkPTE5MTM2NzImaWNpZDI9cHJvZHVjdHMgZ3JpZDpwNDE3MTY4IiwidG9rZW4iOiAic2VwaG9yYSJ9fQ%3D%3D&ip=1&_=1499168684901", 
		"LAST");

	web_add_cookie("mbox=PC#e0d808a00e1d49568f6de0b467f78eff.21_18#1562413477|session#2e203f3bdfce42538c843d3d716a9c35#1499170542; DOMAIN=www.sephora.com");

	web_custom_request("cart", 
		"URL=http://www.sephora.com/rest/user/cart", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://www.sephora.com/sole-di-positano-P417168?skuId=1913672&icid2=products%20grid:p417168", 
		"Snapshot=t789.inf", 
		"Mode=HTTP", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.itemsMap.1913672=1&validate_order=false&is_row=false&scope=inline", 
		"LAST");

	 
# 157 "AddItemToCart.c"


	web_custom_request("basket", 
		"URL=https://www.sephora.com/api/shopping-cart/basket", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=http://www.sephora.com/sole-di-positano-P417168?skuId=1913672&icid2=products%20grid:p417168", 
		"Snapshot=t818.inf", 
		"LAST");



	return 0;
}
# 11 "c:\\users\\hanna_tarletskaya\\loadrunner-data\\scripts\\sephora - copy\\sephora_testscript\\\\combined_Sephora_TestScript_copy.c" 2

# 1 "Action1.c" 1
Action1()
{
	web_custom_request("cart", 
		"URL={homeUrl}/rest/user/cart", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Snapshot=t789.inf", 
		"Mode=HTTP", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.itemsMap.{skuID}=1&validate_order=false&is_row=false&scope=inline", 
		"LAST");


	web_custom_request("basket", 
		"URL={homeUrl}/api/shopping-cart/basket", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/json",  
		"Snapshot=t818.inf", 
		"LAST");
	return 0;
}
# 12 "c:\\users\\hanna_tarletskaya\\loadrunner-data\\scripts\\sephora - copy\\sephora_testscript\\\\combined_Sephora_TestScript_copy.c" 2

# 1 "vuser_end.c" 1
vuser_end()
{
	return 0;
}
# 13 "c:\\users\\hanna_tarletskaya\\loadrunner-data\\scripts\\sephora - copy\\sephora_testscript\\\\combined_Sephora_TestScript_copy.c" 2

