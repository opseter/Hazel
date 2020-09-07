#include<Hazel.h>

//若没有定义预处理 HZ_WINDOWS_PLATFORM 
//不能声明并识别出application 是dll导出的
//这里继承的Hazel：：Application 隐去了HZ_API

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