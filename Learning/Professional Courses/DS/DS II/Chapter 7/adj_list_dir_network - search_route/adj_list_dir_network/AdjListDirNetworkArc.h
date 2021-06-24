#ifndef __ADJ_LIST_NETWORK_ARC_H__
#define __ADJ_LIST_NETWORK_ARC_H__

// �ڽӱ�����������
template <class WeightType>
struct AdjListNetworkArc
{
// ���ݳ�Ա:
	int adjVex;								// ��ͷ�������
	WeightType weight;						// �ߵ�Ȩֵ
	AdjListNetworkArc<WeightType> *nextarc; // ��һ���߽���ָ�� 
// ���캯��:
	AdjListNetworkArc();					// �޲����Ĺ��캯��
	AdjListNetworkArc(int v, WeightType w, AdjListNetworkArc<WeightType> * next = NULL);
          // �����ڽӵ�Ϊv��ȨΪw���ڽӱ�
};

// �ڽӱ������������ʵ�ֲ���
template <class WeightType>
AdjListNetworkArc<WeightType>::AdjListNetworkArc()
// �������������һ�����ڽӱ�߽��ߡ����޲ι��캯��
{
	adjVex = -1;
}

template <class WeightType>
AdjListNetworkArc<WeightType>::AdjListNetworkArc(int v, WeightType w, AdjListNetworkArc<WeightType> *next)
// ��������������ڽӵ����Ϊv���ߵ�ȨΪw����һ���߽���ָ��Ϊnext���ڽӱ�
{
	adjVex = v;	
	weight = w;
    nextarc = next;
}

#endif
