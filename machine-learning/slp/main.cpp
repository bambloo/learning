#include <vector>
#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>

using namespace std;

double uniform_rand(double lowerBndr, double upperBndr);
double gauss_rand(double mean, double sigma);
typedef double (*activation_func)(double z);

double origin_func(double z) {
	return z;
}
double step_func(double z)
{
	return  z >= 0 ? 1 : 0;
}

class NeuralNetworkLinear
{
public:
	NeuralNetworkLinear(int unknowns, activation_func activation, double weight_lower = 0.0, double weight_upper = 1.0, double learning_rate = 0.01);
	NeuralNetworkLinear(vector<double>& weights, activation_func activiation, double learning_rate = 0.1);
	double forward(vector<double>& data);
	void backward(vector<double>& data, double label, double output);
	void train(vector<vector<double>> &datas, vector<double> labels, int epochs = 1);

	double compute_loss(vector<vector<double>>& data, vector<double>& labels);

	const vector<double>& weights() { return m_weights; };
private:
	vector<double> m_weights;
	double learning_rate;
	activation_func activation;
};

NeuralNetworkLinear::NeuralNetworkLinear(int unknowns, activation_func activation, double weight_lower, double weight_upper, double learning_rate) 
	: learning_rate(learning_rate), activation(activation)
{
	m_weights.resize(unknowns);
	for (int i = unknowns - 1; i >= 0; i--) {
		m_weights[i] = uniform_rand(weight_lower, weight_upper);
	}
}

NeuralNetworkLinear::NeuralNetworkLinear(vector<double>& weights, activation_func activation, double learning_rate)
	: m_weights(weights), learning_rate(learning_rate), activation(activation)
{
	
}

double NeuralNetworkLinear::forward(vector<double>& data)
{
	int range = min(m_weights.size(), data.size());
	double z = 0.0;
	for (int i = 0; i < range; i++) {
		z += (m_weights[i] * data[i]);
	}
	return activation(z);
}

void NeuralNetworkLinear::backward(vector<double>& data, double label, double output)
{
 	double d_output = label - output;
	if (d_output == 0) {
		return;
	}

	int range = min(m_weights.size(), data.size());
	for (int i = 0; i < range; i++) {
		m_weights[i] += d_output * data[i] * learning_rate;
	}
}

void NeuralNetworkLinear::train(vector<vector<double>>& datas, vector<double> labels, int epochs)
{
	for (int epoch = 0; epoch < epochs; ++epoch) {
		for (size_t i = 0; i < datas.size(); ++i) {
			double output = forward(datas[i]);
 			backward(datas[i], labels[i], output);
		}
	}
}

double NeuralNetworkLinear::compute_loss(vector<vector<double>>& data, vector<double>& labels)
{
	double loss = 0.0;
	for (size_t i = 0; i < data.size(); ++i)
	{
		double output = forward(data[i]);
		loss += pow(labels[i] - output, 2);
	}
	return loss;
}

int main() {
	srand(0);
	NeuralNetworkLinear nnl(4, origin_func);

	double previous_loss = 0x7ffff;
	vector<vector<double>> train_set;
	vector<double> label_set;
	for (int epoch = 0; epoch < 10000; ++epoch)
	{
		train_set.push_back({ uniform_rand(-10, 10), uniform_rand(-10, 10), uniform_rand(-10, 10), 1});
		label_set.push_back(train_set.back()[0] * 2 + train_set.back()[1] * -5 + train_set.back()[2] * 3.2 - 4.2);
	}
	nnl.train(train_set, label_set);

	cout << "����ȨֵΪ";
	for (auto weight : nnl.weights()) {
		cout << "\t" << weight;
	}

	return 0;
}

double uniform_rand(double lowerBndr, double upperBndr)//������Ӻ���
{
	return lowerBndr + ((double)rand() / (RAND_MAX + 1.0)) * (upperBndr - lowerBndr);
}

double gauss_rand(double mean, double sigma)//mean��ֵ��sigma��׼��
{
	double result = 0;
	do
	{
		double x, y, r2;
		do
		{
			x = -1.0 + 2.0 * uniform_rand(0.0, 1.0);
			y = -1.0 + 2.0 * uniform_rand(0.0, 1.0);
			r2 = x * x + y * y;
		} while (r2 > 1.0 || r2 == 0.0);
		result = mean + sigma * y * sqrt(-2.0 * log(r2) / r2);
	} while (result <= 0 || result >= 100);
	return result;
}

