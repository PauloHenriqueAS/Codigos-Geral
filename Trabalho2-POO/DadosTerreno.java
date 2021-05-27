package Trabalho2;

import java.util.ArrayList;

public class DadosTerreno {
	private ArrayList<Terreno> vetTerreno = new ArrayList<Terreno>();
	
	public void cadastrar(Terreno c) {
		this.vetTerreno.add(c);
		Persist.salvarBinario("terrenos.dat", c);//Salvar no arquivo
		System.out.println("Total de terrenos inseridos: ");
		System.out.println(this.vetTerreno.size());
	}
	
	public void listar(){
		for (Terreno objeto: this.vetTerreno) {
			objeto.mostarDados();
		}
	}
	
	public Terreno buscar(int id) {
		Terreno c = null;
		for ( Terreno objeto: this.vetTerreno) {
			if (objeto.getIdImovel() == id) {
				c = objeto;
				break;
			}
		}
		return c;
	}
	
	//este método usa o método buscar já implementado
	public boolean excluir(int id){
		Terreno terrenoRemove = this.buscar(id);
		
		if(terrenoRemove != null) {
			this.vetTerreno.remove(terrenoRemove);
			return true;
		}else {
			return false;
		}
	}
}
