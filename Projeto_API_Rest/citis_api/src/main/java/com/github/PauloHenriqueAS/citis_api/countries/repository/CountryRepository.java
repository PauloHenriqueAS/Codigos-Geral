package com.github.PauloHenriqueAS.citis_api.countries.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import com.github.PauloHenriqueAS.citis_api.countries.Country;

public interface CountryRepository extends JpaRepository<Country, Long> {
}
