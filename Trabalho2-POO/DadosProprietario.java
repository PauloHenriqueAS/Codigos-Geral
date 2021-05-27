package Trabalho2;

import java.util.ArrayList;

public class DadosProprietario {
	private ArrayList<Proprietario> vetProprietario = new ArrayList<Proprietario>();
	
	public void cadastrar(Proprietario c) {
		this.vetProprietario.add(c);
		Persist.salvarBinario("proprietarios.dat", c);//Salvar no arquivo
		System.out.println("Total de proprietarios inseridas: ");
		System.out.println(this.vetProprietario.size());
	}
	
	public void listar(){
		for (Proprietario objeto: this.vetProprietario) {
			objeto.mostarDados();
		}
	}
	
	public Proprietario buscar(String nome) {
		Proprietario c = null;
		for ( Proprietario objeto: this.vetProprietario) {
			if (objeto.getNome().equals(nome)) {
				c = objeto;
				break;
			}
		}
		return c;
	}
	
	//este método usa o método buscar já implementado
	public boolean excluir(String nome){
		Proprietario proprietarioRemove = this.buscar(nome);
		
		if(proprietarioRemove != null) {
			this.vetProprietario.remove(proprietarioRemove);
			return true;
		}else {
			return false;
		}
	}
}
