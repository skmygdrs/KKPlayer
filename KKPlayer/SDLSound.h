#include "IKKAudio.h"
#ifndef SDLSound_H_
#define SDLSound_H_
#include "../../SDL-1.2.15/include/SDL.h"
class CSDLSound: public IKKAudio
{
	public:
		CSDLSound();
		~CSDLSound();
		virtual void SetWindowHAND(int m_hwnd);
		virtual void SetUserData(void* UserData);
		/********������Ƶ�ص�����*********/
		virtual void SetAudioCallBack(pfun fun);
		/***********��ʼ����Ƶ�豸*********/
		virtual int InitAudio();
		/*******��ȡ��Ƶ����********/
		virtual void ReadAudio();	   
		virtual void Start();	   
		virtual void Stop();	   
		/*********�ر�**********/
		virtual void CloseAudio();	
		/*********��������************/
		virtual void SetVolume(long value);
		virtual long GetVolume();

public:
		void KKSDLCall( Uint8 *stream, int len);
   private:
		pfun m_pFun;
		void* m_UserData;
		long m_Vol;
};
#endif