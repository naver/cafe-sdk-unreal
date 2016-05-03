package com.epicgames.ue4;

import com.naver.glink.android.sample.OBBDownloaderService;
import com.naver.glink.android.sample.DownloaderActivity;


public class DownloadShim
{
	public static OBBDownloaderService DownloaderService;
	public static DownloaderActivity DownloadActivity;
	public static Class<DownloaderActivity> GetDownloaderType() { return DownloaderActivity.class; }
}

