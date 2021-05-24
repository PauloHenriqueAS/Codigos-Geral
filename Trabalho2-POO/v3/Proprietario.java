package Trabalho2;

import java.time.LocalDate;

public class Proprietario extends Cliente{
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
		System.out.println("Data Cadastro: " + getDataCadastro());
	}
	
	/*Metodos
	public void cadastrarImovel(String endereco, String cpfproprietario){}
	public String pesquisarProprietario(String nomeProprietario){}*/
	
}
