#include "StdAfx.h"
#include "KKSound.h"
#pragma comment (lib,"dxguid.lib")
#pragma comment (lib,"dsound.lib")
#define MAX_AUDIO_BUF 4   
#define BUFFERNOTIFYSIZE 1024*4//16384//1024*16*8
DSBPOSITIONNOTIFY m_pDSPosNotify[MAX_AUDIO_BUF];  
HANDLE m_event[MAX_AUDIO_BUF];  
int sample_rate=44100;  //PCM sample rate  
int channels=2;         //PCM channel number  
int bits_per_sample=16; //bits per sample  
CKKSound::CKKSound(void)
{   
	
}
void CKKSound::InitAudio()
{
	IsClose=true;
	lpDirectSound=NULL;
	res=WAIT_OBJECT_0;  
	m_pFun=NULL;
	m_UserData=NULL;
	m_pDSBuffer8=NULL; //used to manage sound buffers.  
	ppDSBuffer=NULL;
	m_pDSNotify=NULL;
	buf=NULL;  
	buf_len=0;  
	offset=BUFFERNOTIFYSIZE;  
	HRESULT hr = DirectSoundCreate8(NULL, &lpDirectSound, NULL);
	if(FAILED(hr))
	{
		//error;
	}
	//m_pDSBuffer8->Lock(0,BUFFERNOTIFYSIZE,&buf,&buf_len,NULL,NULL,0);
	//m_pFun(m_UserData,(char*)buf,buf_len);
	//m_pDSBuffer8->Unlock(buf,buf_len,NULL,0);   
}
CKKSound::~CKKSound(void)
{
}
void CKKSound::SetUserData(void* UserData)
{
	m_UserData=UserData;
}
void CKKSound:: SetWindowHAND(int m_hwnd)
{

	HWND hwnd=(HWND)m_hwnd;
	HRESULT hr = lpDirectSound->SetCooperativeLevel(hwnd,DSSCL_PRIORITY);
	if(FAILED(hr))
	{
        //error
	}
    
	DSBUFFERDESC dsbd;  
	memset(&dsbd,0,sizeof(dsbd));  
	dsbd.dwSize=sizeof(dsbd);  
	dsbd.dwFlags=DSBCAPS_GLOBALFOCUS | DSBCAPS_CTRLPOSITIONNOTIFY |DSBCAPS_GETCURRENTPOSITION2|DSBCAPS_CTRLVOLUME;  
	dsbd.dwBufferBytes=MAX_AUDIO_BUF*BUFFERNOTIFYSIZE;   
	//WAVE Header  
	dsbd.lpwfxFormat=(WAVEFORMATEX*)malloc(sizeof(WAVEFORMATEX));  
	dsbd.lpwfxFormat->wFormatTag=WAVE_FORMAT_PCM;     
	/* format type */  
	(dsbd.lpwfxFormat)->nChannels=channels;            
	/* number of channels (i.e. mono, stereo...) */  
	(dsbd.lpwfxFormat)->nSamplesPerSec=sample_rate;       
	/* sample rate */  
	(dsbd.lpwfxFormat)->nAvgBytesPerSec=sample_rate*(bits_per_sample/8)*channels;   
	/* for buffer estimation */  
	(dsbd.lpwfxFormat)->nBlockAlign=(bits_per_sample/8)*channels;          
	/* block size of data */  
	(dsbd.lpwfxFormat)->wBitsPerSample=bits_per_sample;       
	/* number of bits per sample of mono data */  
	(dsbd.lpwfxFormat)->cbSize=0;  

	 hr=lpDirectSound->CreateSoundBuffer(&dsbd,&ppDSBuffer,NULL);
	 if(FAILED(hr))
	 {
		 //error
	 }

	 if( FAILED(ppDSBuffer->QueryInterface(IID_IDirectSoundBuffer8,(LPVOID*)&m_pDSBuffer8)))
	 {  
		 //error
	 }  
	 //Get IDirectSoundNotify8  
	 if(FAILED(ppDSBuffer->QueryInterface(IID_IDirectSoundNotify,(LPVOID*)&m_pDSNotify)))
	 {  
		//error
	 }  
	 for(int i =0;i<MAX_AUDIO_BUF;i++)
	 {  
		 m_pDSPosNotify[i].dwOffset =i*BUFFERNOTIFYSIZE;  
		 m_event[i]=::CreateEvent(NULL,false,false,NULL);   
		 m_pDSPosNotify[i].hEventNotify=m_event[i];  
	 } 

	 m_pDSNotify->SetNotificationPositions(MAX_AUDIO_BUF,m_pDSPosNotify);  
	 m_pDSNotify->Release();  

	 IsClose=false;
	 m_pDSBuffer8->SetCurrentPosition(0);  
	 m_pDSBuffer8->Play(0,0,DSBPLAY_LOOPING);

}
void CKKSound::SetVolume(long value)
{
	if(m_pDSBuffer8!=NULL)
	 m_pDSBuffer8->SetVolume(value);
	
}
long CKKSound::GetVolume()
{
   long ll=0;
  HRESULT hr = m_pDSBuffer8->GetVolume(&ll);
   return ll;
}
/*****调节音量算法*******/
void RaiseVolume(char* buf, UINT32 size, UINT32 uRepeat, double vol)//buf为需要调节音量的音频数据块首地址指针，size为长度，uRepeat为重复次数，通常设为1，vol为增益倍数,可以小于1  
{  
	if (!size)  
	{  
		return;  
	}  
	for (int i = 0; i < size;)  
	{  
		signed long minData = -0x8000; //如果是8bit编码这里变成-0x80  
		signed long maxData = 0x7FFF;//如果是8bit编码这里变成0xFF  

		signed short wData = buf[i + 1];  
		wData = MAKEWORD(buf[i], buf[i + 1]);  
		signed long dwData = wData;  

		for (int j = 0; j < uRepeat; j++)  
		{  
			dwData = dwData * vol;  
			if (dwData < -0x8000)  
			{  
				dwData = -0x8000;  
			}  
			else if (dwData > 0x7FFF)  
			{  
				dwData = 0x7FFF;  
			}  
		}  
		wData = LOWORD(dwData);  
		buf[i] = LOBYTE(wData);  
		buf[i + 1] = HIBYTE(wData);  
		i += 2;  
	}  
} 
void CKKSound::PlayAudio()
{
	m_Lock.Lock();
	if(IsClose)
	{
		m_Lock.Unlock();
		return;
	}
	m_Lock.Unlock();
	 if((res >=WAIT_OBJECT_0)&&(res <=WAIT_OBJECT_0+3))
	 { 
			m_pDSBuffer8->Lock(offset,BUFFERNOTIFYSIZE,&buf,&buf_len,NULL,NULL,0);
			
			if(m_pFun!=NULL)
			{
				//memset(buf,0,buf_len);
				m_pFun(m_UserData,(char*)buf,buf_len);
				//RaiseVolume((char*)buf, buf_len, 1, 5);
			}
			m_pDSBuffer8->Unlock(buf,buf_len,NULL,0);    
			offset+=buf_len;  
			offset %= (BUFFERNOTIFYSIZE * MAX_AUDIO_BUF);  
	 }
	 res=WaitForMultipleObjects (MAX_AUDIO_BUF, m_event, FALSE, INFINITE);  
	 int i=0;
	 i++;
}
void CKKSound::CloseAudio()
{
	m_Lock.Lock();
	IsClose=true;
	m_Lock.Unlock();
	for(int i=0;i< MAX_AUDIO_BUF ;i++)
	{
	  CloseHandle(m_event[i]);
	}
	if(lpDirectSound!=NULL)
	{
		lpDirectSound->Release();
		lpDirectSound=NULL;
		/*m_pDSBuffer8->Lock(offset,BUFFERNOTIFYSIZE,&buf,&buf_len,NULL,NULL,0);
		memset(buf,0,buf_len);
		m_pDSBuffer8->Unlock(buf,buf_len,NULL,0);  */ 
	}
    

}
void CKKSound::SetAudioCallBack(pfun fun)
{
	m_pFun=fun;
}