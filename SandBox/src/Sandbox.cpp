#include<Hazel.h>

//��û�ж���Ԥ���� HZ_WINDOWS_PLATFORM 
//����������ʶ���application ��dll������
//����̳е�Hazel����Application ��ȥ��HZ_API

class SandBox:public Hazel:: Application
{
public:
    SandBox()
    {
    
    }

    ~SandBox()
    {

    }

};

Hazel::Application* Hazel::CreateApplication()
{
    return new SandBox();
}