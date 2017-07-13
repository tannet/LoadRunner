ScriptScenario()
{
	//	lr_think_time(10);
	int r;
	//char * r;
	char* IEVersion;
	
	char* wordForCategory;
	//int number;
	
	int itemsTotal;
	int itemsOnPage;
	int numberOfItemsToAdd;
	
	char* wordForSearch;
		
	int itemNumber;
	int itemSelected;
	
	int itemsInCart;
	
	char* str;
		int sz;
	
	/*if(r<=25){
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
	}*/
	
	/*if(r<=25){
		IEVersion = {IE);
	}
	else if((r>25)&&(r<=30)){
		IEVersion = {IEVersion_7};
	}
	else if((r>30)&&(r<=40)){
		IEVersion = {IEVersion_8});
	}
	else if((r>40)&&(r<=60)){
		IEVersion = {IEVersion_9};
	}
	else if((r>60)&&(r<=70)){
		IEVersion =  {IEVersion_10};
	}
	else{
		IEVersion = {IEVersion_11};
	}
	lr_param_sprintf("browserVersion", "Mozilla/5.0 (compatible; MSIE {IEVersion}");*/
	
///////////////////////////////////////////////////// HOME
	//random IE version for search
	r = rand() %100 + 1;
	//lr_param_sprintf(r,"{random1_100}");
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
		//add choosing of browser version or not?
	
		//set header for browser
		web_add_header("User-Agent", "{browserVersion}");
		web_custom_request("001_OpenHomePage",
			"URL={homeUrl}/",
			"Method=GET",
			"Resource=0",
			"RecContentType=text/html",
			"Referer=",
			"Snapshot=t001.inf",
			"Mode=HTTP",
			LAST);

	lr_end_transaction("001_OpenHomePage", LR_AUTO);

///////////////////////////////////////////// Category or Search
	//lr_think_time(10);
	
	r = rand()%10;
	if(r < 5){
		lr_start_transaction("002_OpenCategory");
	
			//probability of 50% for category choose
			r = rand()%10;
			if (r<5){
				wordForCategory = "fragrance";
			}
			else{
				wordForCategory = "makeup-tools";
			}
			lr_save_string(wordForCategory, "wordForCategory");
			
			//choosing subcategory
			if(strcmp(wordForCategory, "makeup-tools")==0){
				r = rand()%5;
			} else if (strcmp(wordForCategory, "fragrance")==0){
				r = rand()%3;								//TASK how add the 4th item too?
			}
			lr_param_sprintf("category_path", "$.categories.sub_categories[%d].seo_path", r); // in category fragrance $.categories.sub_categories[3].seo_path is not exist
			
			web_set_max_html_param_len("100000");
			web_reg_save_param("jsonForCategory",
				"LB=<script id=\"searchResult\" type=\"text/json\" seph-pagedata>",
				"RB=</script>",
				LAST);
			
			web_add_header("User-Agent", "{browserVersion}");
			web_custom_request("002_OpenCategory",
				"URL={homeUrl}/{wordForCategory}",
				"Method=GET",
				"Resource=0",
				"RecContentType=text/html",
				"Referer={homeUrl}",
				"Snapshot=t002.inf",
				"Mode=HTTP",
				LAST);
			
			lr_eval_json("Buffer={jsonForCategory}",
				  "JsonObject=json_obj_category",
						 LAST);
			lr_json_get_values("JsonObject=json_obj_category",
							   "ValueParam=linkForSubcategory",
							   "QueryString={category_path}",
							   LAST);
		
		lr_end_transaction("002_OpenCategory", LR_AUTO);
		

		
		 

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
				LAST);
			
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
			
		lr_end_transaction("003_OpenSubcategory", LR_AUTO);
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
					LAST);
				
				web_add_header("User-Agent", "{browserVersion}");
				web_custom_request("004_Search",
					"URL={homeUrl}/search/search.jsp?keyword={wordForSearch}&mode=all",
					"Method=GET",
					"Resource=0",
					"RecContentType=text/html",
					"Referer={homeUrl}",
					"Snapshot=t004.inf",
					"Mode=HTTP",
					LAST);
				
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
			
		lr_end_transaction("004_Search", LR_AUTO);
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
		LAST);

	lr_end_transaction("005_OpenItem", LR_AUTO);

	
	
	
	
// TASK decide how mush products should be added
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
				LAST);
			
		lr_end_transaction("006_AddItemToCart", LR_AUTO);
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
			LAST);
		
		lr_eval_json("Buffer={jsonForBasket}",
				 "JsonObject=json_obj_basket", 
				 "LAST");
		lr_json_get_values("JsonObject=json_obj_basket",
					   "ValueParam=numberOfItemsInCart",
					   "QueryString=$.itemCount",
					   "LAST");
					   
		itemsInCart = atoi(lr_eval_string("{numberOfItemsInCart}"));

		if(itemsInCart==numberOfItemsToAdd){
			lr_end_transaction("007_CheckBasket", LR_PASS);
		}
		else{
			lr_end_transaction("007_CheckBasket", LR_FAIL);
		}

	
	return 0;
}
