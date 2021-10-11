all
# Exclude rule to allow HTML tags in markdown file
exclude_rule 'MD033'
# Exclude line length for code blocks and tables.
rule 'MD013', :code_blocks => false, :tables => false, :link=>false
rule 'MD029', :style => :ordered
