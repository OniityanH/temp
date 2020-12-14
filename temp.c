	/* proc ctc */
	pCTC_cfg = g_LAYOUT_Get_Ctc_Cfg_In_Tsrs();
	if (STCC_OK == g_LAYOUT_Check_Address_Is_Ads_Base_Address((ULONG)pCTC_cfg))
	{
		for (i = 0U; i < pCTC_cfg->TSRS_CTC_CFG_Ctc_Num; ++i)
		{
			pCTC = g_LAYOUT_Get_Ctc_Data_In_Tsrs((BYTE_8)i);
			if (STCC_OK == g_LAYOUT_Check_Address_Is_Ads_Base_Address((ULONG)pCTC))
			{
				psdm = (TSRS_SDM_GAL_Interface_Struct*)g_LAYOUT_Get_Special_Sdm_Interface_In_TSRS(pCTC->TSRS_CTC_DATA_CtcsId);
				if (STCC_OK == g_LAYOUT_Check_Address_Is_Ads_Base_Address((ULONG)psdm))
				{
					if (SDM_INTERFACE_DAT_DIR_IN == (unsigned int)dir)
					{
						g_GAL_SDM_Interface_Proc_Dev_Need_Snd(psdm, dir, pCTC->TSRS_CTC_DATA_CtcsId, SUBMSGTYPE_CTCIN, MSG_TYPE_EXCHANGE_DATA);
					}
					else if (SDM_INTERFACE_DAT_DIR_OUT == (unsigned int)dir)
					{
						g_GAL_SDM_Interface_Proc_Dev_Need_Snd(psdm, dir, pCTC->TSRS_CTC_DATA_CtcsId, SUBMSGTYPE_CTCOUT, MSG_TYPE_EXCHANGE_DATA);
					}
					else
					{
						; /* for code review */
					}
				}
			}
		}
	}