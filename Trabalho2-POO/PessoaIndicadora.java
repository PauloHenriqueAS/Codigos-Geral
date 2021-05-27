package Trabalho2;

import java.io.Serializable;

import Trabalho2.Valida; //Classe contendo a verificacao do cpf

public class PessoaIndicadora implements PrintDados, Serializable{
	private String nome;
	private String cpf;
	
	public PessoaIndicadora() {
		
	}
	public PessoaIndicadora(String nome, String cpf) {
		setNome(nome);
		setCpf(cpf);
	}
	
	public String getNome() {
		return nome;
	}
	public boolean setNome(String nome) {
		if(nome.length() > 0) {
			this.nome = nome;	
			return true;
		}else {
			return false;
		}
	}
	public String getCpf() {
		return cpf;
	}
	public boolean setCpf(String cpf) {
		if(cpf.length() > 0) {	
			boolean aux = Valida.valindoCPF(cpf);
			if(aux == true) {
				this.cpf = cpf;
				return true;
			}else {
				return false;	
			}
		}else {
			return false;
		}
	}
	
	public void mostarDados(){
		System.out.println("Nome: " + getNome());
		System.out.println("CPF: " + getCpf());
	}
	
}
