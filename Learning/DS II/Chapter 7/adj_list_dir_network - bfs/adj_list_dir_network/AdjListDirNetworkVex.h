#ifndef __ADJ_LIST_NETWORK_VEX_H__
#define __ADJ_LIST_NETWORK_VEX_H__

// �ڽӱ�����������
template <class ElemType, class WeightType>
struct AdjListNetWorkVex
{
// ���ݳ�Ա:
	ElemType data;						// ����Ԫ��ֵ
	AdjListNetworkArc<WeightType> *firstarc;
		// ָ���ڽ�����߽���ָ��

// ���캯��:
	AdjListNetWorkVex();				// �޲����Ĺ��캯��
	AdjListNetWorkVex(ElemType val, 
		AdjListNetworkArc<WeightType> *adj = NULL);
		// �в����Ĺ��캯��
};

// �ڽӱ������������ʵ�ֲ���
template <class ElemType, class WeightType>
AdjListNetWorkVex<ElemType, WeightType>::AdjListNetWorkVex()
// �������������һ���ն����㡪���޲ι��캯��
{
	firstarc = NULL;	
}

template <class ElemType, class WeightType>
AdjListNetWorkVex<ElemType, WeightType>::AdjListNetWorkVex(ElemType  val, 
	AdjListNetworkArc<WeightType> *adj)
// �����������������Ϊval,��Ϊeg�Ķ���
{
	data = val;
	firstarc = adj;
}

#endif
