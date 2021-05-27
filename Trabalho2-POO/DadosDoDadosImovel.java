package Trabalho2;

import java.util.ArrayList;

public class DadosDoDadosImovel {
	private ArrayList<DadosImovel> vetDadosImovel = new ArrayList<DadosImovel>();
	
	public void cadastrar(DadosImovel c) {
		this.vetDadosImovel.add(c);
		Persist.salvarBinario("dadosImovel.dat", c);//Salvar no arquivo
		System.out.println("Total de dados dos imoveis inseridos: ");
		System.out.println(this.vetDadosImovel.size());
	}
	
	public void listar(){
		for (DadosImovel objeto: this.vetDadosImovel) {
			objeto.mostarDados();
		}
	}
	
	public DadosImovel buscar(int id) {
		DadosImovel c = null;
		for ( DadosImovel objeto: this.vetDadosImovel) {
			if (objeto.getIdImovel() == id) {
				c = objeto;
				break;
			}
		}
		return c;
	}
	
	//este método usa o método buscar já implementado
	public boolean excluir(int id){
		DadosImovel dadosImovelRemove = this.buscar(id);
		
		if(dadosImovelRemove != null) {
			this.vetDadosImovel.remove(dadosImovelRemove);
			return true;
		}else {
			return false;
		}
	}
}
