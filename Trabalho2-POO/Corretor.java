package Trabalho2;

import java.io.Serializable;
import java.time.LocalDate;
import java.util.ArrayList;

public class Corretor extends Funcionarios implements PrintDados, Serializable{
	private static final double comissao = 0.05;
	private LocalDate dataInicioCarreira;
	private boolean formado;
	private double salarioFinal;
	private Transacao transacao;
	private double vendasMes;
	
	public Corretor() {	}
	
	public Corretor(String nome, String cpf, String email, String sexo, String cargo, double salBase, LocalDate data, boolean formado) {
		super(nome, cpf, email, sexo, cargo, salBase);
		setDataInicioCarreira(data);
		setFormado(formado);
	}
	
	public double getComissao() {
		return comissao;
	}
	
	public double getVendasMes() {
		return vendasMes;
	}

	public void setVendasMes(double vendasMes) {
		this.vendasMes = vendasMes;
	}

	public LocalDate getDataInicioCarreira() {
		return dataInicioCarreira;
	}
	public void setDataInicioCarreira(LocalDate dataInicioCarreira) {
		this.dataInicioCarreira = dataInicioCarreira;
	}
	public boolean isFormado() {
		return formado;
	}
	public void setFormado(boolean formado) {
		this.formado = formado;
	}

	public Transacao getTransacao() {
		return transacao;
	}

	public void setTransacao(Transacao transacao) {
		this.transacao = transacao;
	}

	public double getSalarioFinal() {
		return salarioFinal;
	}

	public boolean setSalarioFinal(double salarioFinal) {
		if(salarioBase >= 0) {
			this.salarioFinal = salarioFinal;
			return true;
		}else {
			return false;
		}
	}
	
	public double calcularSalarioFinal(){
		double aux;
		aux = getSalarioBase() + (comissao*vendasMes);
		return  aux;
	}
	public void zeraVendasMes() {
		setVendasMes(0);
	}
	
	public void mostarDados(){
		super.mostarDados();
		System.out.println("Comissão: " + getComissao());
		System.out.println("Início da carreira: " + getDataInicioCarreira());
		System.out.println("Formado: " + isFormado());
		System.out.println("Salário final: " + getSalarioFinal());
		transacao.mostarDados();
		System.out.println("Vendas Mês: " + getVendasMes());
	}
	
}
