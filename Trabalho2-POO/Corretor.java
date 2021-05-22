package Trabalho2;

import java.time.LocalDate;
import java.util.ArrayList;

public class Corretor extends Funcionarios{
	private static final double comissao = 0.05;
	private int negociosFechados;
	private LocalDate dataInicioCarreira;
	private boolean formado;
	private double salarioFinal;
	private Transacao transacao;
	private static int nextNegocio = 1;
	
	public Corretor() {	}
	
	public Corretor(String nome, String cpf, String email, String sexo, String cargo, double salBase, LocalDate data, boolean formado) {
		super(nome, cpf, email, sexo, cargo, salBase);
		setDataInicioCarreira(data);
		setFormado(formado);
		setNegociosFechados();
	}
	
	public double getComissao() {
		return comissao;
	}
	public int getNegociosFechados() {
		return negociosFechados;
	}
	public void setNegociosFechados() {
		this.negociosFechados = nextNegocio;
		nextNegocio++;
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
	
	/*Fazer set e get salarioFinal*/
	/*metodos
	public String consultarNegociosFechados(){
		return "Implementar";
	}
	public float calcularSalarioFinal(String cpf, String nroContrato){
		return  super.getSalarioBase();
	}
	*/
}
