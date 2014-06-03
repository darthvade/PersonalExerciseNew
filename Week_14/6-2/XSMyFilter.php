<?php
    class XSXyzFilter implements XSDataFilter
    {
        public function process($data, $cs = false)
        {
			$data['Description'] = '++++++++++++++++++++++++++'.$data['Description'];
            return $data;
        }
        public function processDoc($doc)
        {
            // $doc->addTerm('subject', '特殊词');
        }
    }
?>
