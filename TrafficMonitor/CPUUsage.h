#pragma once
#include <Pdh.h>
#include <PdhMsg.h>

class CCPUUsage
{
public:
    CCPUUsage()
    {}

    ~CCPUUsage()
    {}

    void SetUseCPUTimes(bool use_get_system_times);		//���û�ȡCPU�����ʵķ�ʽ����ͨ��GetSystemTimes����Pdh
    int GetCPUUsage();

private:
    int GetCPUUsageByGetSystemTimes();
    int GetCPUUsageByPdh();

private:
    bool m_use_get_system_times{ true };		//�Ƿ�ʹ��GetSysTime���API����ȡCPU������

    PDH_RAW_COUNTER m_last_rawData{};//�������CPUʹ���ʵ���һ������
    bool m_first_get_CPU_utility{ true };

    FILETIME m_preidleTime{};
    FILETIME m_prekernelTime{};
    FILETIME m_preuserTime{};

};

class CCpuFreq
{
public:
    CCpuFreq();
    bool GetCpuFreq(float& freq) const;

private:
    float max_cpu_freq = 0;
};
