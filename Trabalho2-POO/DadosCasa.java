package Trabalho2;

import java.util.ArrayList;

public class DadosCasa {
	private ArrayList<Casa> vetCasa = new ArrayList<Casa>();
	
	public void cadastrar(Casa c) {
		this.vetCasa.add(c);
		Persist.salvarBinario("casas.dat", c);//Salvar no arquivo
		System.out.println("Total de casas inseridas: ");
		System.out.println(this.vetCasa.size());
	}
	
	public void listar(){
		for (Casa objeto: this.vetCasa) {
			objeto.mostarDados();
		}
	}
	
	public Casa buscar(int id) {
		Casa c = null;
		for ( Casa objeto: this.vetCasa) {
			if (objeto.getIdImovel() == id) {
				c = objeto;
				break;
			}
		}
		return c;
	}
	
	//este método usa o método buscar já implementado
	public boolean excluir(int id){
		Casa casaRemove = this.buscar(id);
		
		if(casaRemove != null) {
			this.vetCasa.remove(casaRemove);
			return true;
		}else {
			return false;
		}
	}
}
