package Trabalho2;

import java.time.LocalDate;

public class proprietario extends Cliente{
	private LocalDate dataCadastro;//Date

	public LocalDate getDataCadastro() {
		return dataCadastro;
	}
	public void setDataCadastro(LocalDate dataCadastro) {
		this.dataCadastro = dataCadastro;
	}
	
	/*Metodos
	public void cadastrarImovel(String endereco, String cpfproprietario){}
	public String pesquisarProprietario(String nomeProprietario){}*/
	
}
