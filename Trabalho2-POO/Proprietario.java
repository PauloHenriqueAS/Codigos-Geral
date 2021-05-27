package Trabalho2;

import java.io.Serializable;
import java.time.LocalDate;

public class Proprietario extends Cliente implements PrintDados, Serializable{
	private LocalDate dataCadastro;//Date
	
	public Proprietario() {}
	public Proprietario(String nome, String cpf, String email, String sexo, String prof, String estadoC) {
		super(nome, cpf, email,sexo, prof,estadoC);
		dataCadastro = LocalDate.now();
	}
	
	public LocalDate getDataCadastro() {
		return dataCadastro;
	}
	
	public void mostarDados(){
		super.mostarDados();
		System.out.println("Data Cadastro: " + getDataCadastro());
	}
	
}
